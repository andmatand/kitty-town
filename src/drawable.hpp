#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SDL2/SDL.h>

struct Drawable {
    SDL_Rect* rect;
    SDL_Texture* texture;
};

#endif // DRAWABLE_HPP
