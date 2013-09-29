#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>

#include "camera.hpp"
#include "character.hpp"
#include "kitty.hpp"
#include "room.hpp"
#include "scenery.hpp"
#include "sprite.hpp"

#define NUM_ROOMS 1

class Game {
    public:
        Game();
        void CreateRooms();
        void DestroyEverything();
        void Draw(SDL_Renderer*);
        bool ProcessInput();
        void Update();

    private:
        Camera camera;
        Character* player;
        Room* currentRoom;
        Room rooms[NUM_ROOMS];
};

#endif // GAME_HPP
