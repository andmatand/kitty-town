#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <SDL2/SDL.h>
#include "collisionmask.hpp"
#include "drawable.hpp"

struct AnimationFrame {
    SDL_Rect rect;
    unsigned int delay;
    CollisionMask* collisionMask;
};

struct Animation {
    SDL_Texture* texture;
    AnimationFrame* frames;
    int numFrames;
    bool loop;
};

#endif // ANIMATION_HPP
