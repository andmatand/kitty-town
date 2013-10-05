#include "collisionmask.hpp"

// DEBUG
//#include <iostream>

CollisionMask::CollisionMask(SDL_Surface* surface, SDL_Rect* rect) {
    size.w = rect->w;
    size.h = rect->h;

    // Initialize our map to the size of the surface
    map = new bool[size.w * size.h];

    SDL_PixelFormat *pixelFormat = surface->format;
    uint32_t* pixels = (uint32_t*) surface->pixels;
    uint32_t pixel, temp;
    uint8_t alpha;

    for (int y = rect->y; y < (rect->y + rect->h); y++) {
        for (int x = rect->x; x < (rect->x + rect->w); x++) {
            //std::cout << "(" << x << ", " << y << ")\n";
            //

            SDL_LockSurface(surface);
            pixel = pixels[y * surface->w + x];
            SDL_UnlockSurface(surface);

            // Get the alpha component of the pixel color
            temp = pixel & pixelFormat->Amask;  // Isolate the alpha component
            temp = temp >> pixelFormat->Ashift; // Shift it down to 8-bit
            temp = temp << pixelFormat->Aloss;  // Expand to a full 8-bit number
            alpha = (uint8_t) temp;

            //std::cout << "bit alpha: " << alpha << std::endl;

            bool bit;
            if (alpha == 255) {
                bit = true;
            }
            else {
                bit = false;
            }

            int mapX = x - rect->x;
            int mapY = y - rect->y;

            // Set this bit of our map
            map[(mapY * size.w) + mapX] = bit;
        }
    }

    //std::cout << "CollisionMask map:\n";
    //for (int y = 0; y < size.h; y++) {
    //    for (int x = 0; x < size.w; x++) {
    //        if (map[(y * size.w) + x]) {
    //            std::cout << "*";
    //        }
    //        else {
    //            std::cout << ".";
    //        }
    //    }
    //    std::cout << "\n";
    //}
}

CollisionMask::~CollisionMask() {
    delete map;
}

bool CollisionMask::PixelOverlap(int x, int y,
                                 bool flipHorizontal, bool flipVertical) {
    if (flipHorizontal) {
        x = (size.w - 1) - x;
    }
    if (flipVertical) {
        y = (size.h - 1) - y;
    }

    return map[y * size.w + x];
}

bool CollisionMask::MaskOverlap(CollisionMask* mask1,
                                Position position1,
                                bool flipHorizontal1,
                                bool flipVertical1,
                                CollisionMask* mask2,
                                Position position2,
                                bool flipHorizontal2,
                                bool flipVertical2) {
    Position overlapPos;
    overlapPos.x = (position1.x > position2.x ? position1.x : position2.x);
    overlapPos.y = (position1.y > position2.y ? position1.y : position2.y);

    Size overlapSize;
    if (position1.x + mask1->size.w < position2.x + mask2->size.w) {
        //std::cout << "width: option 1\n";
        overlapSize.w = (position1.x + mask1->size.w) - overlapPos.x;
    }
    else {
        //std::cout << "width: option 2\n";
        overlapSize.w = (position2.x + mask2->size.w) - overlapPos.x;
    }
    if (position1.y + mask1->size.h < position2.y + mask2->size.h) {
        //std::cout << "height: option 1\n";
        overlapSize.h = (position1.y + mask1->size.h) - overlapPos.y;
    }
    else {
        //std::cout << "height: option 2\n";
        overlapSize.h = (position2.y + mask2->size.h) - overlapPos.y;
    }

    //std::cout << "sprite1: (" << position1.x << ", " <<
    //    position1.y << ")\n";
    //std::cout << "sprite2: (" << position2.x << ", " <<
    //    position2.y << ")\n";

    //std::cout << "overlapPos: (" << overlapPos.x << ", " <<
    //    overlapPos.y << ")\n";
    //std::cout << "overlapSize: (" << overlapSize.w << ", " <<
    //    overlapSize.h << ")\n";

    for (int y = overlapPos.y; y < overlapPos.y + overlapSize.h; y++) {
        for (int x = overlapPos.x; x < overlapPos.x + overlapSize.w; x++) {
            // Translate the coordinates to find the position in mask1
            Position posInMask1;
            posInMask1.x = x - position1.x;
            posInMask1.y = y - position1.y;
            //std::cout << "posInMask1: (" << posInMask1.x << ", " <<
            //    posInMask1.y << ")\t";

            // Translate the coordinates to find the position in mask2
            Position posInMask2;
            posInMask2.x = x - position2.x;
            posInMask2.y = y - position2.y;
            //std::cout << "posInMask2: (" << posInMask2.x << ", " <<
            //    posInMask2.y << ")\n";

            if (mask1->PixelOverlap(posInMask1.x, posInMask1.y,
                                    flipHorizontal1, flipVertical1) &&
                mask2->PixelOverlap(posInMask2.x, posInMask2.y,
                                    flipHorizontal2, flipVertical2)) {
                //std::cout << "COLLISION\n";
                return true;
            }
        }
    }

    //std::cout << "NO COLLISION\n";
    return false;
}
