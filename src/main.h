#include <SDL2/SDL.h>
#include <algorithm>
#include <vector>
#include <iostream>
//#include <math.h>

#define FPS 60
#define GRAPHICS_SCALE 4
#define SCREEN_W 80
#define SCREEN_H 60

int SCALED_SCREEN_W = SCREEN_W * GRAPHICS_SCALE;
int SCALED_SCREEN_H = SCREEN_H * GRAPHICS_SCALE;

SDL_Window* WINDOW;
SDL_Renderer* RENDERER;
SDL_Texture* SPRITE_TEXTURE;
SDL_Texture* SCENERY_TEXTURE;

enum KEY {
    KEY_UP = 0,
    KEY_RIGHT = 1,
    KEY_DOWN = 2,
    KEY_LEFT = 3
};

struct Position {
    int x;
    int y;
};

struct Size {
    int w;
    int h;
};

static void InitEverything();
static void DestroyEverything();
