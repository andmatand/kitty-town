#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <SDL2/SDL.h>

#define FPS 60
#define GRAPHICS_SCALE 4
#define SCREEN_W 80
#define SCREEN_H 60

extern int SCALED_SCREEN_W;
extern int SCALED_SCREEN_H;

extern SDL_Window* WINDOW;
extern SDL_Renderer* RENDERER;
extern SDL_Texture* SPRITE_TEXTURE;
extern SDL_Texture* SCENERY_TEXTURE;

#endif // GLOBALS_HPP
