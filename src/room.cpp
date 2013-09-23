#ifndef ROOM_CPP
#define ROOM_CPP

#include "camera.cpp"
#include "sprite.cpp"

using namespace std;

class Room {
    public:
        void AddSprite(Sprite* sprite) {
            this->sprites.push_back(sprite);
        }

        void DestroyEverything() {
            for (vector<Sprite*>::iterator sprite = sprites.begin();
                 sprite != sprites.end(); sprite++) {
                delete (*sprite);
            }
        }

        void Draw(Camera camera) {
            SortSpritesForDrawOrder();

            for (vector<Sprite*>::iterator sprite = sprites.begin();
                 sprite != sprites.end(); sprite++) {
                (*sprite)->Draw(camera);
            }
        }

        void SortSpritesForDrawOrder() {
            //std::sort(sprites.begin(), sprites.end());
            std::sort(sprites.begin(), sprites.end(), Sprite::PointerCompare());
        }

        void Update() {
            // Run Update() on all sprites
            for (vector<Sprite*>::iterator sprite = sprites.begin();
                 sprite != sprites.end(); sprite++) {
                (*sprite)->Update();
            }

            // Run DoPhysics() on all sprites that are PhysicsBody objects
            for (vector<Sprite*>::iterator sprite = sprites.begin();
                 sprite != sprites.end(); sprite++) {
                //PhysicsBody* physicsBody = static_cast<PhysicsBody*>(*sprite);
                //if (physicsBody) {
                //    physicsBody->DoPhysics(&sprites);
                //}
                (*sprite)->DoPhysics(&sprites);
            }

            // Run DoPostPhysics() on all sprites that are PhysicsBody objects
            for (vector<Sprite*>::iterator sprite = sprites.begin();
                 sprite != sprites.end(); sprite++) {
                //PhysicsBody* physicsBody = static_cast<PhysicsBody*>(*sprite);
                //if (physicsBody) {
                //    physicsBody->DoPostPhysics();
                //}
                (*sprite)->DoPostPhysics();
            }
        }

    private:
        vector<Sprite*> sprites;
};

#endif // ROOM_CPP
