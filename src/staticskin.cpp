#include "staticskin.hpp"

StaticSkin::StaticSkin(SDL_Texture* texture, SDL_Rect* rect) {
    drawable = new Drawable();
    drawable->texture = texture;
    drawable->rect = rect;
}

StaticSkin::~StaticSkin() {
    delete drawable;
    drawable = NULL;
}

Drawable* StaticSkin::GetDrawable() {
    return drawable;
}
