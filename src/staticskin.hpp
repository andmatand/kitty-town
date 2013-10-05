#ifndef STATICSKIN_HPP
#define STATICSKIN_HPP

#include <SDL2/SDL.h>
#include "drawable.hpp"
#include "skin.hpp"

class StaticSkin : public Skin {
    public:
        StaticSkin(SDL_Texture*, SDL_Rect*);
        ~StaticSkin();
        Drawable* GetDrawable();

    private:
        Drawable* drawable;
};

#endif // STATICSKIN_HPP
