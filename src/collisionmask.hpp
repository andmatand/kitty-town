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
        uint8_t GetPixelAlpha(SDL_Surface* surface, int pixelIndex);
        bool IsPixelOverlap(int x, int y, bool flipHorizontal,
                            bool flipVertical);
        static bool IsMaskCollision(CollisionMask* mask1,
                                    Position spritePosition1,
                                    bool flipHorizontal1,
                                    bool flipVertical1,
                                    CollisionMask* mask2,
                                    Position spritePosition2,
                                    bool flipHorizontal2,
                                    bool flipVertical2);
        static bool IsRectOverlap(Position, Size, Position, Size);

    private:
        bool* map;
        Position offset;
        Size size;
};

#endif // COLLISIONMASK_HPP
