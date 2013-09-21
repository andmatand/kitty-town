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
            break;
        }

        game.Update(timeDelta);
        game.Draw(RENDERER);
    }

    /*

    // Get the dimensions of the dude texture int w, h;
    SDL_QueryTexture(dudeTexture, NULL, NULL, &w, &h);

    // Create a rect for the location of the dude texture
    SDL_Rect dudeRect;
    dudeRect.x = 300;
    dudeRect.y = 200;
    dudeRect.w = w * 3;
    dudeRect.h = h * 6;

    unsigned int timeDelta;
    unsigned int previousTicks = SDL_GetTicks();
    int x, y;
    x = windowW / 2;
    y = windowH / 2;
    float zoom = 5;
    while (true) {
        timeDelta = SDL_GetTicks() - previousTicks;
        previousTicks = SDL_GetTicks();

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
            else if (e.type == SDL_WINDOWEVENT &&
                     e.window.event == SDL_WINDOWEVENT_FOCUS_LOST) {
                while (true) {
                    SDL_Delay(10);
                    SDL_Event e;
                    if (SDL_PollEvent(&e)) {
                        if (e.type == SDL_WINDOWEVENT &&
                            e.window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
                            break;
                    }
                }
            }
        } 


        // Copy the dude texture to the rendering context
        SDL_Rect srcRect;
        srcRect.x = 0;//rand() % 2;
        srcRect.y = 0;//rand() % 2;
        srcRect.w = w;
        srcRect.h = h;

        //float zoomMult =  .9 + (((float) rand() / RAND_MAX) / 10);
        float zoomMult = (float) (98 + (rand() % (104 - 98))) / 100;
        printf("%f\n", zoomMult);
        zoom *= zoomMult;
        if (zoom < 1) {
            zoom = 1;
        }
        else if (zoom > 75) {
            zoom = 75;
        }
        dudeRect.w = (w * zoom);
        dudeRect.h = (h * zoom);
        dudeRect.x = x - (dudeRect.w / 2);
        dudeRect.y = y - (dudeRect.h / 2);
        SDL_RenderCopy(renderer, dudeTexture,
                       &srcRect,
                       &dudeRect);

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

    WINDOW = SDL_CreateWindow("KITTY TOWN ADVENTURES",
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
    KITTY_ANIMATIONS[0].loop = true;
    KITTY_ANIMATIONS[0].numFrames = 2;
    KITTY_ANIMATIONS[0].frames = new AnimationFrame[2];
    KITTY_ANIMATIONS[0].frames[0].rect = kittyRect1;
    KITTY_ANIMATIONS[0].frames[0].delay = 100;
    KITTY_ANIMATIONS[0].frames[1].rect = kittyRect2;
    KITTY_ANIMATIONS[0].frames[1].delay = 100;
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
