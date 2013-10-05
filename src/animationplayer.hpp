#ifndef ANIMATIONPLAYER_HPP
#define ANIMATIONPLAYER_HPP

#include <SDL2/SDL.h>
#include "animation.hpp"
#include "collisionmask.hpp"
#include "drawable.hpp"

class AnimationPlayer {
    public:
        AnimationPlayer();
        ~AnimationPlayer();
        CollisionMask* GetCollisionMask();
        Drawable* GetDrawable();
        void SetAnimation(Animation*);
        void Update();

    private:
        Animation* animation;
        int currentFrameIndex;
        Drawable* drawable;
        unsigned int frameTimer;
};

#endif // ANIMATIONPLAYER_HPP
