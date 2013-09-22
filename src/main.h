#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
//#include <math.h>

#define GRAPHICS_SCALE 4

SDL_Window* WINDOW;
SDL_Renderer* RENDERER;
SDL_Texture* SPRITE_TEXTURE;
int WINDOW_W;
int WINDOW_H;

enum KEY {
    KEY_UP = 0,
    KEY_RIGHT = 1,
    KEY_DOWN = 2,
    KEY_LEFT = 3
};

static void InitEverything();
static void DestroyEverything();
