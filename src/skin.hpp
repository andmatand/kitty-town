#ifndef SKIN_HPP
#define SKIN_HPP

#include "animation.hpp"
#include "drawable.hpp"

class Skin {
    public:
        Skin();
        Drawable* GetDrawable();
        void SetAnimations(Animation*);
        void SetCurrentAnimation(int);
        void Update();

    private:
        Animation* animations;
        AnimationPlayer animationPlayer;
        int animationIndex;
};

#endif // SKIN_HPP
