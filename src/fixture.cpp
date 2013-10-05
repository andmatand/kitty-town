#include "fixture.hpp"

Fixture::Fixture(FIXTURE_TYPE fixtureType) {
    SDL_Rect* rect;
    CollisionMask* collisionMask;

    switch(fixtureType) {
        case FIXTURE_TYPE::HOUSE1:
            rect = &SPRITE_RECTS[4];
            collisionMask = COLLISION_MASKS[1];
            break;
    }

    // Set our size to the size of our SDL_Rect
    size.w = rect->w;
    size.h = rect->h;

    skin = new StaticSkin(SPRITE_TEXTURE, rect, collisionMask);
}
