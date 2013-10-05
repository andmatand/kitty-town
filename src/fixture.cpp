#include "fixture.hpp"

Fixture::Fixture(FIXTURE_TYPE fixtureType) {
    SDL_Rect* rect;

    switch(fixtureType) {
        case FIXTURE_TYPE::HOUSE1:
            rect = &SPRITE_RECTS[4];
            break;
    }

    // Set our size to the size of our SDL_Rect
    size.w = rect->w;
    size.h = rect->h;

    skin = new StaticSkin(SPRITE_TEXTURE, rect);
}
