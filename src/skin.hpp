#ifndef SKIN_HPP
#define SKIN_HPP

#include "drawable.hpp"

class Skin {
    public:
        virtual ~Skin();
        virtual Drawable* GetDrawable() = 0;
};

#endif // SKIN_HPP
