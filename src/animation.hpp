#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "drawable.hpp"

struct AnimationFrame {
    SDL_Rect rect;
    unsigned int delay;
};

struct Animation {
    SDL_Texture* texture;
    AnimationFrame* frames;
    int numFrames;
    bool loop;
};

class AnimationPlayer {
    public:
        AnimationPlayer();
        Drawable* GetDrawable();
        void SetAnimation(Animation*);
        void Update();

    private:
        Animation* animation;
        int currentFrameIndex;
        unsigned int frameTimer;
};

#endif // ANIMATION_HPP
