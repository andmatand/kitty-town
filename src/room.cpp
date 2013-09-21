#ifndef ROOM_CPP
#define ROOM_CPP

#include "sprite.cpp"

class Room {
    public:
        void AddSprite(Sprite* sprite) {
            this->sprites.push_back(*sprite);
        }

        void Draw() {
            for (std::vector<Sprite>::iterator sprite = sprites.begin();
                 sprite != sprites.end(); sprite++) {
                sprite->Draw();
            }
        }

        void Update(unsigned int timeDelta) {
            for (std::vector<Sprite>::iterator sprite = sprites.begin();
                 sprite != sprites.end(); sprite++) {
                sprite->Update(timeDelta);
            }
        }

    private:
        std::vector<Sprite> sprites;
};

#endif // ROOM_CPP
