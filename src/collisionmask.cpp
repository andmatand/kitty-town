#include "collisionmask.hpp"

#ifdef DEBUG
#include <iostream>
#endif

uint8_t CollisionMask::GetPixelAlpha(SDL_Surface* surface, int pixelIndex) {
    SDL_PixelFormat *pixelFormat = surface->format;
    uint32_t* pixels = (uint32_t*) surface->pixels;
    uint32_t pixel, temp;
    uint8_t alpha;

    SDL_LockSurface(surface);
    pixel = pixels[pixelIndex];
    SDL_UnlockSurface(surface);

    // Get the alpha component of the pixel color
    temp = pixel & pixelFormat->Amask;  // Isolate the alpha component
    temp = temp >> pixelFormat->Ashift; // Shift it down to 8-bit
    temp = temp << pixelFormat->Aloss;  // Expand to a full 8-bit number
    alpha = (uint8_t) temp;

    return alpha;
}

CollisionMask::CollisionMask(SDL_Surface* surface, SDL_Rect* rect) {
    // Initialize dimension-finding variables
    int x1 = rect->x + rect->w;
    int y1 = rect->y + rect->h;
    int x2 = rect->x - 1;
    int y2 = rect->y - 1;

    bool findingDimensions = true;
    while (true) {
        for (int y = rect->y; y < (rect->y + rect->h); y++) {
            for (int x = rect->x; x < (rect->x + rect->w); x++) {
                uint8_t alpha = GetPixelAlpha(surface, y * surface->w + x);

                bool bit;
                if (alpha == 255) {
                    bit = true;
                }
                else {
                    bit = false;
                }

                if (findingDimensions) {
                    if (bit) {
                        // Adjust the dimension-finding coordinates if necessary
                        if (x < x1) x1 = x;
                        if (y < y1) y1 = y;
                        if (x > x2) x2 = x;
                        if (y > y2) y2 = y;
                    }
                }
                else {
                    // Translate the image coordinates to coordinates on the
                    // mask
                    int mapX = x - rect->x - offset.x;
                    int mapY = y - rect->y - offset.y;

                    // If this coordinate is inside the mask
                    if (mapX >= 0 && mapX < size.w &&
                        mapY >= 0 && mapY < size.h) {
                        // Set this bit of our map
                        map[(mapY * size.w) + mapX] = bit;
                    }
                }
            }
        }

        if (findingDimensions) {
            findingDimensions = false;
            
            // Set the mask size to the discovered dimensions
            size.w = (x2 - x1) + 1;
            size.h = (y2 - y1) + 1;

            // Set the mask offset to the top left of mask data
            offset.x = x1 - rect->x;
            offset.y = y1 - rect->y;

            // Initialize our map to the size of the mask
            map = new bool[size.w * size.h];
        }
        else {
            break;
        }
    }

#ifdef DEBUG
    std::cout << "CollisionMask map:\n";
    for (int y = 0; y < size.h; y++) {
        for (int x = 0; x < size.w; x++) {
            if (map[(y * size.w) + x]) {
                std::cout << "*";
            }
            else {
                std::cout << ".";
            }
        }
        std::cout << "\n";
    }
#endif
}

CollisionMask::~CollisionMask() {
    delete [] map;
}

bool CollisionMask::IsMaskCollision(CollisionMask* mask1,
                                    Position position1,
                                    bool flipHorizontal1,
                                    bool flipVertical1,
                                    CollisionMask* mask2,
                                    Position position2,
                                    bool flipHorizontal2,
                                    bool flipVertical2) {
    // Apply the mask offset to the sprite positions
    position1.x = position1.x + mask1->offset.x;
    position1.y = position1.y + mask1->offset.y;
    position2.x = position2.x + mask2->offset.x;
    position2.y = position2.y + mask2->offset.y;

    // If the masks are not even overlapping
    if (!IsRectOverlap(position1, mask1->size, position2, mask2->size)) {
        // Don't bother with any further (slower) checks
        return false;
    }

    Position overlapPos;
    overlapPos.x = (position1.x > position2.x ? position1.x : position2.x);
    overlapPos.y = (position1.y > position2.y ? position1.y : position2.y);

    Size overlapSize;
    if (position1.x + mask1->size.w < position2.x + mask2->size.w) {
        overlapSize.w = (position1.x + mask1->size.w) - overlapPos.x;
    }
    else {
        overlapSize.w = (position2.x + mask2->size.w) - overlapPos.x;
    }
    if (position1.y + mask1->size.h < position2.y + mask2->size.h) {
        overlapSize.h = (position1.y + mask1->size.h) - overlapPos.y;
    }
    else {
        overlapSize.h = (position2.y + mask2->size.h) - overlapPos.y;
    }

    for (int y = overlapPos.y; y < overlapPos.y + overlapSize.h; y++) {
        for (int x = overlapPos.x; x < overlapPos.x + overlapSize.w; x++) {
            // Translate the coordinates to find the position in mask1
            Position posInMask1;
            posInMask1.x = x - position1.x;
            posInMask1.y = y - position1.y;

            // Translate the coordinates to find the position in mask2
            Position posInMask2;
            posInMask2.x = x - position2.x;
            posInMask2.y = y - position2.y;

            if (mask1->IsPixelOverlap(posInMask1.x, posInMask1.y,
                                      flipHorizontal1, flipVertical1) &&
                mask2->IsPixelOverlap(posInMask2.x, posInMask2.y,
                                      flipHorizontal2, flipVertical2)) {
                return true;
            }
        }
    }

    return false;
}

bool CollisionMask::IsPixelOverlap(int x, int y,
                                   bool flipHorizontal, bool flipVertical) {
    if (flipHorizontal) {
        x = (size.w - 1) - x;
    }
    if (flipVertical) {
        y = (size.h - 1) - y;
    }

    return map[y * size.w + x];
}

bool CollisionMask::IsRectOverlap(Position position1, Size size1,
                                  Position position2, Size size2) {
    if ((position1.x <= position2.x + (size2.w - 1) &&
         position1.x + (size1.w - 1) >= position2.x) &&
        (position1.y <= position2.y + (size2.h - 1) &&
         position1.y + (size1.h - 1) >= position2.y)) {
        return true;
    } else {
        return false;
    }
}
