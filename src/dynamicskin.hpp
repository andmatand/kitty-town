#ifndef DYNAMICSKIN_HPP
#define DYNAMICSKIN_HPP

#include "animation.hpp"
#include "animationplayer.hpp"
#include "collisionmask.hpp"
#include "drawable.hpp"
#include "globals.hpp"
#include "skin.hpp"

class DynamicSkin : public Skin {
    public:
        DynamicSkin();
        ~DynamicSkin();
        CollisionMask* GetCollisionMask();
        Drawable* GetDrawable();
        //void SetAnimations(Animation*);
        void SetCurrentAnimation(int);
        void Update();

    private:
        Animation* animations;
        AnimationPlayer animationPlayer;
        int animationIndex;
};

#endif // DYNAMICSKIN_HPP
