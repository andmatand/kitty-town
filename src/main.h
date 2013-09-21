#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
//#include <math.h>

#define FPS_MAX 60
#define GRAPHICS_SCALE 4

SDL_Window* WINDOW;
SDL_Renderer* RENDERER;
SDL_Texture* SPRITE_TEXTURE;
int WINDOW_W;
int WINDOW_H;

static void InitEverything();
static void DestroyEverything();
