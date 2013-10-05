#include "main.hpp"

// DEBUG
#include <iostream>

int main(int argc, char* argv[]) {
    InitSDL();
    AssetLoader::LoadEverything();

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
            std::cout << "skipped update\n";
        }

        game.Draw(RENDERER);
    }

    AssetLoader::DestroyEverything();
    DestroySDL();

    return 0;
}

void InitSDL() {
    SDL_Init(SDL_INIT_VIDEO);

    //WINDOW = SDL_CreateWindow("KITTY TOWN",
    //                          SDL_WINDOWPOS_CENTERED,
    //                          SDL_WINDOWPOS_CENTERED,
    //                          0,
    //                          0,
    //                          SDL_WINDOW_FULLSCREEN_DESKTOP);
    WINDOW = SDL_CreateWindow("KITTY TOWN",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              SCALED_SCREEN_W,
                              SCALED_SCREEN_H,
                              0);

    RENDERER = SDL_CreateRenderer(WINDOW, -1,
                                  SDL_RENDERER_ACCELERATED |
                                  SDL_RENDERER_PRESENTVSYNC);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest"); // ALL the pixels!
    SDL_RenderSetLogicalSize(RENDERER, SCALED_SCREEN_W, SCALED_SCREEN_H);

    // Hide the cursor
    SDL_ShowCursor(0);
}

void DestroySDL() {
    SDL_DestroyRenderer(RENDERER);
    SDL_DestroyWindow(WINDOW);
    SDL_Quit();
}

