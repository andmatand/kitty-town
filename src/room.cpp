#ifndef ROOM_CPP
#define ROOM_CPP

#include "sprite.cpp"

class Room {
    public:
        void AddSprite(Sprite* sprite) {
            this->sprites.push_back(sprite);
        }

        void DestroyEverything() {
            for (std::vector<Sprite*>::iterator sprite = sprites.begin();
                 sprite != sprites.end(); sprite++) {
                delete (*sprite);
            }
        }

        void Draw() {
            for (std::vector<Sprite*>::iterator sprite = sprites.begin();
                 sprite != sprites.end(); sprite++) {
                (*sprite)->Draw();
            }
        }

        void Update(unsigned int timeDelta) {
            // Run PreUpdate() on all sprites
            //for (std::vector<Sprite*>::iterator sprite = sprites.begin();
            //     sprite != sprites.end(); sprite++) {
            //    (*sprite)->PreUpdate();
            //}

            // Run Update() on all sprites
            for (std::vector<Sprite*>::iterator sprite = sprites.begin();
                 sprite != sprites.end(); sprite++) {
                Character* character = static_cast<Character*>(*sprite);
                if (character) {
                    character->Update(timeDelta);
                }
                else {
                    (*sprite)->Update(timeDelta);
                }
            }

            // Run DoPhysics() on all sprites
            for (std::vector<Sprite*>::iterator sprite = sprites.begin();
                 sprite != sprites.end(); sprite++) {
                (*sprite)->DoPhysics();
            }

            // Run DoPostPhysics() on all sprites
            for (std::vector<Sprite*>::iterator sprite = sprites.begin();
                 sprite != sprites.end(); sprite++) {
                (*sprite)->DoPostPhysics();
            }
        }

    private:
        std::vector<Sprite*> sprites;
};

#endif // ROOM_CPP
