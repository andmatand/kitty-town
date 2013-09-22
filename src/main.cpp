#include "main.h"
#include "game.cpp"

using namespace std;

int main(int argc, char* argv[]) {
    InitEverything();

    Game game;

    unsigned int timeDelta;
    unsigned int previousTicks = SDL_GetTicks();
    while (true) {
        timeDelta = SDL_GetTicks() - previousTicks;
        previousTicks = SDL_GetTicks();

        // If the game gave a quit signal
        if (game.ProcessInput()) {
            game.DestroyEverything();
            break;
        }

        game.Update(timeDelta);
        game.Draw(RENDERER);
    }

    /*
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                break;
            else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
                break;
            else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_UP)
                y -= .2 * timeDelta;
            else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_DOWN)
                y += .2 * timeDelta;
            else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_LEFT)
                x -= .2 * timeDelta;
            else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RIGHT)
                x += .2 * timeDelta;
        } 
    */

    DestroyEverything();

    return 0;
}

static void DestroySDL() {
    SDL_DestroyRenderer(RENDERER);
    SDL_DestroyWindow(WINDOW);
    SDL_Quit();
}

static void InitSDL() {
    SDL_Init(SDL_INIT_VIDEO);

    WINDOW = SDL_CreateWindow("KITTY TOWN",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              320,
                              200,
                              0);
                              //SDL_WINDOW_FULLSCREEN_DESKTOP);
    RENDERER = SDL_CreateRenderer(WINDOW, -1,
                                  SDL_RENDERER_ACCELERATED |
                                  SDL_RENDERER_PRESENTVSYNC);

    // Hide the cursor
    SDL_ShowCursor(0);

    SDL_GetWindowSize(WINDOW, &WINDOW_W, &WINDOW_H);
}

static void InitAssets() {
    // Load the sprite sheet into a surface
    SDL_Surface* spriteSurface = SDL_LoadBMP("res/img/sprites.bmp");

    // Create a texture from the sprite surface
    SPRITE_TEXTURE = SDL_CreateTextureFromSurface(RENDERER, spriteSurface);

    // Free the sprite sheet surface
    SDL_FreeSurface(spriteSurface);
}

void DestroyAssets() {
    SDL_DestroyTexture(SPRITE_TEXTURE);
}

static void InitSkins() {
    SDL_Rect kittyRect1;
    kittyRect1.x = 0;
    kittyRect1.y = 0;
    kittyRect1.w = KITTY_W;
    kittyRect1.h = KITTY_H;

    SDL_Rect kittyRect2;
    kittyRect2.x = KITTY_W;
    kittyRect2.y = 0;
    kittyRect2.w = KITTY_W;
    kittyRect2.h = KITTY_H;

    KITTY_ANIMATIONS[0].texture = SPRITE_TEXTURE;
    KITTY_ANIMATIONS[0].loop = false;
    KITTY_ANIMATIONS[0].numFrames = 1;
    KITTY_ANIMATIONS[0].frames = new AnimationFrame[1];
    KITTY_ANIMATIONS[0].frames[0].rect = kittyRect1;
    KITTY_ANIMATIONS[0].frames[0].delay = 0;

    KITTY_ANIMATIONS[1].texture = SPRITE_TEXTURE;
    KITTY_ANIMATIONS[1].loop = true;
    KITTY_ANIMATIONS[1].numFrames = 2;
    KITTY_ANIMATIONS[1].frames = new AnimationFrame[2];
    KITTY_ANIMATIONS[1].frames[0].rect = kittyRect1;
    KITTY_ANIMATIONS[1].frames[0].delay = 200;
    KITTY_ANIMATIONS[1].frames[1].rect = kittyRect2;
    KITTY_ANIMATIONS[1].frames[1].delay = 200;
}

static void DestroySkins() {
}

static void InitEverything() {
    InitSDL();
    InitAssets();
    InitSkins();
}

static void DestroyEverything() {
    DestroySkins();
    DestroyAssets();
    DestroySDL();
}
