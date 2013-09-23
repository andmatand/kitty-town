#include "main.h"
#include "game.cpp"

using namespace std;

int main(int argc, char* argv[]) {
    InitEverything();

    Game game;

    unsigned int updateTimer = 999;
    unsigned int timeDelta;
    unsigned int previousTicks = SDL_GetTicks();
    while (true) {
        timeDelta = SDL_GetTicks() - previousTicks;
        previousTicks = SDL_GetTicks();

        updateTimer += timeDelta;

        // If the game gave a quit signal
        if (game.ProcessInput()) {
            game.DestroyEverything();
            break;
        }

        if (updateTimer >= 1000 / FPS) {
            updateTimer = 0;

            game.Update();
        }
        else {
            cout << "skipped update\n";
        }

        game.Draw(RENDERER);
    }

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
                              0,
                              0,
                              SDL_WINDOW_FULLSCREEN_DESKTOP);
    //WINDOW = SDL_CreateWindow("KITTY TOWN",
    //                          SDL_WINDOWPOS_CENTERED,
    //                          SDL_WINDOWPOS_CENTERED,
    //                          SCALED_SCREEN_W,
    //                          SCALED_SCREEN_H,
    //                          0);

    RENDERER = SDL_CreateRenderer(WINDOW, -1,
                                  SDL_RENDERER_ACCELERATED |
                                  SDL_RENDERER_PRESENTVSYNC);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest"); // ALL the pixels!
    SDL_RenderSetLogicalSize(RENDERER, SCALED_SCREEN_W, SCALED_SCREEN_H);

    // Hide the cursor
    SDL_ShowCursor(0);
}

static void InitAssets() {
    // Load the sprite texture
    SDL_Surface* spriteSurface = SDL_LoadBMP("res/img/sprites.bmp");
    SPRITE_TEXTURE = SDL_CreateTextureFromSurface(RENDERER, spriteSurface);
    SDL_FreeSurface(spriteSurface);

    // Load the scenery texture
    SDL_Surface* scenerySurface = SDL_LoadBMP("res/img/scenery.bmp");
    SCENERY_TEXTURE = SDL_CreateTextureFromSurface(RENDERER, scenerySurface);
    SDL_FreeSurface(scenerySurface);
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

    KITTY_ANIMATIONS = new Animation[NUM_KITTY_ANIMATIONS];

    // Create the kitty standing animation
    KITTY_ANIMATIONS[0].texture = SPRITE_TEXTURE;
    KITTY_ANIMATIONS[0].loop = false;
    KITTY_ANIMATIONS[0].numFrames = 1;
    KITTY_ANIMATIONS[0].frames = new AnimationFrame[1];
    KITTY_ANIMATIONS[0].frames[0].rect = kittyRect1;
    KITTY_ANIMATIONS[0].frames[0].delay = 0;

    // Create the kitty walking animation
    KITTY_ANIMATIONS[1].texture = SPRITE_TEXTURE;
    KITTY_ANIMATIONS[1].loop = true;
    KITTY_ANIMATIONS[1].numFrames = 2;
    KITTY_ANIMATIONS[1].frames = new AnimationFrame[2];
    KITTY_ANIMATIONS[1].frames[0].rect = kittyRect2;
    KITTY_ANIMATIONS[1].frames[0].delay = 4;
    KITTY_ANIMATIONS[1].frames[1].rect = kittyRect1;
    KITTY_ANIMATIONS[1].frames[1].delay = 4;

    HOUSE_ANIMATIONS = new Animation[NUM_HOUSE_ANIMATIONS];

    // Define the house 1 animation
    SDL_Rect house1Rect;
    house1Rect.x = 0;
    house1Rect.y = 0;
    house1Rect.w = 21;
    house1Rect.h = 15;
    HOUSE_ANIMATIONS[0].texture = SCENERY_TEXTURE;
    HOUSE_ANIMATIONS[0].loop = false;
    HOUSE_ANIMATIONS[0].numFrames = 1;
    HOUSE_ANIMATIONS[0].frames = new AnimationFrame[1];
    HOUSE_ANIMATIONS[0].frames[0].rect = house1Rect;
    HOUSE_ANIMATIONS[0].frames[0].delay = 0;
}

static void DestroySkins() {
    for (int i = 0; i < NUM_KITTY_ANIMATIONS; i++) {
        delete KITTY_ANIMATIONS[i].frames;
    }

    for (int i = 0; i < NUM_HOUSE_ANIMATIONS; i++) {
        delete HOUSE_ANIMATIONS[i].frames;
    }
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
