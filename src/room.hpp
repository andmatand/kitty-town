#ifndef ROOM_HPP
#define ROOM_HPP

#include <algorithm>
#include <vector>

#include "camera.hpp"
#include "sprite.hpp"

class Room {
    public:
        void AddSprite(Sprite*);
        void DestroyEverything();
        void Draw(Camera camera);
        void SortSpritesForDrawOrder();
        void Update();

    private:
        std::vector<Sprite*> sprites;
};

#endif // ROOM_HPP
