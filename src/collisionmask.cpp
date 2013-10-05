#include "collisionmask.hpp"

// DEBUG
#include <iostream>

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
            map[mapY * size.w + mapX] = bit;
        }
    }
}

CollisionMask::~CollisionMask() {
    delete map;
}

bool CollisionMask::IsCollision(int x, int y,
                                bool flipHorizontal, bool flipVertical) {
    if (flipHorizontal) {
        x = (size.w - 1) - x;
    }
    if (flipVertical) {
        y = (size.h - 1) - y;
    }

    return map[y * size.w + x + 1];
}
