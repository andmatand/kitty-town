#include "staticskin.hpp"

StaticSkin::StaticSkin(SDL_Texture* texture, SDL_Rect* rect,
                       CollisionMask* collisionMask) {
    drawable = new Drawable();
    drawable->texture = texture;
    drawable->rect = rect;
    this->collisionMask = collisionMask;
}

StaticSkin::~StaticSkin() {
    delete drawable;
    drawable = NULL;
}

CollisionMask* StaticSkin::GetCollisionMask() {
    return collisionMask;
}

Drawable* StaticSkin::GetDrawable() {
    return drawable;
}
