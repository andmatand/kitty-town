#ifndef GAME_CPP
#define GAME_CPP

#include "kitty.cpp"
#include "room.cpp"
#include "sprite.cpp"

class Game {
    public:
        Game() {
            CreateRooms();
            this->currentRoom = &this->rooms[0];
        }

        void CreateRooms() {
            Room* town = new Room();
            Kitty* kitty = new Kitty();

            town->AddSprite(kitty);
            this->rooms[0] = *town;
        }

        void Draw(SDL_Renderer* renderer) {
            // Clear the screen
            SDL_RenderClear(renderer);

            // Draw the current room
            this->currentRoom->Draw();

            // Flip the backbuffer
            SDL_RenderPresent(renderer);
        }

        void Update(unsigned int timeDelta) {
            this->currentRoom->Update(timeDelta);
        }

        bool ProcessInput() {
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT)
                    return true;
                    break;
            }

            return false;
        }

    private:
        Room* currentRoom;
        Room rooms[1];
};

#endif // GAME_CPP
