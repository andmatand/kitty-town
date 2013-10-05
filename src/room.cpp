#include "room.hpp"

void Room::AddSprite(Sprite* sprite) {
    this->sprites.push_back(sprite);
}

void Room::DestroyEverything() {
    for (std::vector<Sprite*>::iterator sprite = sprites.begin();
         sprite != sprites.end(); sprite++) {
        delete (*sprite);
    }
}

void Room::Draw(Camera camera) {
    SortSpritesForDrawOrder();

    for (std::vector<Sprite*>::iterator sprite = sprites.begin();
         sprite != sprites.end(); sprite++) {
        (*sprite)->Draw(camera);
    }
}

void Room::SortSpritesForDrawOrder() {
    std::sort(sprites.begin(), sprites.end(), Sprite::PointerCompare());
}

void Room::Update() {
    // Run Update() on all sprites
    for (std::vector<Sprite*>::iterator sprite = sprites.begin();
         sprite != sprites.end(); sprite++) {
        (*sprite)->Update();
    }

    // Run Move() on all PhysicsBody objects
    for (std::vector<Sprite*>::iterator sprite = sprites.begin();
         sprite != sprites.end(); sprite++) {
        static_cast<PhysicsBody*>(*sprite)->Move(&sprites);
    }

    // Run DoPostPhysics() on all sprites that are PhysicsBody objects
    for (std::vector<Sprite*>::iterator sprite = sprites.begin();
         sprite != sprites.end(); sprite++) {
        //PhysicsBody* physicsBody = static_cast<PhysicsBody*>(*sprite);
        //if (physicsBody) {
        //    physicsBody->DoPostPhysics();
        //}
        static_cast<PhysicsBody*>(*sprite)->PostMove();
    }
}
