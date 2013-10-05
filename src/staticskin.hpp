#ifndef STATICSKIN_HPP
#define STATICSKIN_HPP

#include <SDL2/SDL.h>
#include "collisionmask.hpp"
#include "drawable.hpp"
#include "skin.hpp"

class StaticSkin : public Skin {
    public:
        StaticSkin(SDL_Texture*, SDL_Rect*, CollisionMask*);
        ~StaticSkin();
        CollisionMask* GetCollisionMask();
        Drawable* GetDrawable();

    private:
        CollisionMask* collisionMask;
        Drawable* drawable;
};

#endif // STATICSKIN_HPP
