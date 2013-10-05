#ifndef COLLISIONMASK_HPP
#define COLLISIONMASK_HPP

#include <SDL2/SDL.h>
#include <stdint.h>
#include "position.hpp"
#include "size.hpp"

class CollisionMask {
    public:
        CollisionMask(SDL_Surface*, SDL_Rect*);
        ~CollisionMask();
        bool PixelOverlap(int x, int y, bool flipHorizontal, bool flipVertical);
        static bool MaskOverlap(CollisionMask* mask1,
                                Position position1,
                                bool flipHorizontal1,
                                bool flipVertical1,
                                CollisionMask* mask2,
                                Position position2,
                                bool flipHorizontal2,
                                bool flipVertical2);

    private:
        bool* map;
        Size size;
};

#endif // COLLISIONMASK_HPP
