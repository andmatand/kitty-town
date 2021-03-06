#include "game.hpp"

Game::Game() {
    CreateRooms();

    this->currentRoom = &this->rooms[0];
}

void Game::CreateRooms() {
    player = new Kitty();
    player->SetPosition(27, 20);

    Fixture* house = new Fixture(FIXTURE_TYPE::HOUSE1);
    house->SetPosition(5, 10);

    rooms[0].AddSprite(house);
    rooms[0].AddSprite(player);
}

void Game::DestroyEverything() {
    for (int i = 0; i < NUM_ROOMS; i++) {
        rooms[i].DestroyEverything();
    }

    currentRoom = NULL;
    player = NULL;
}

void Game::Draw(SDL_Renderer* renderer) {
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Fill the background with a color
    SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
    SDL_RenderFillRect(renderer, NULL);

    // Center the camera on the player
    camera.CenterOn(player->GetPosition(), player->GetSize());

    // Draw the current room
    this->currentRoom->Draw(camera);

    // Flip the backbuffer
    SDL_RenderPresent(renderer);
}

bool Game::ProcessInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return true; // Signal to quit the program
        }
        else if (event.type == SDL_WINDOWEVENT) {
            // If the window focus was lost
            if (event.window.event == SDL_WINDOWEVENT_FOCUS_LOST) {
                // Suspend execution of the game until the window
                // regains focus, so as to not use tons of CPU
                // because of the lack of v-sync
                while (true) {
                    SDL_Delay(10);
                    SDL_Event event;
                    if (SDL_PollEvent(&event)) {
                        if (event.type == SDL_QUIT) {
                            return true; // Signal to quit the program
                        }
                        if (event.type == SDL_WINDOWEVENT &&
                            event.window.event ==
                            SDL_WINDOWEVENT_FOCUS_GAINED) break;
                    }
                }
            }
        }
        else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                return true;
            }
            else if (event.key.keysym.sym == SDLK_F11) {
                uint32_t flags = SDL_GetWindowFlags(WINDOW);
                uint32_t newFlags;
                newFlags = (flags & SDL_WINDOW_FULLSCREEN_DESKTOP ?
                            0 : SDL_WINDOW_FULLSCREEN_DESKTOP);
                SDL_SetWindowFullscreen(WINDOW, newFlags);
            }
        }
    }

    const Uint8* keyState = SDL_GetKeyboardState(NULL);

    if(keyState[SDL_SCANCODE_LEFT] || keyState[SDL_SCANCODE_A]) {
        player->KeyPressed(KEY_LEFT);
    }
    if(keyState[SDL_SCANCODE_RIGHT] || keyState[SDL_SCANCODE_D]) {
        player->KeyPressed(KEY_RIGHT);
    }
    if(keyState[SDL_SCANCODE_UP] || keyState[SDL_SCANCODE_W]) {
        player->KeyPressed(KEY_UP);
    }
    if(keyState[SDL_SCANCODE_DOWN] || keyState[SDL_SCANCODE_S]) {
        player->KeyPressed(KEY_DOWN);
    }

    return false; // Signal to not quit the program
}

void Game::Update() {
    this->currentRoom->Update();
}
