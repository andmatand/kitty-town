#ifndef SKIN_CPP
#define SKIN_CPP

#include "animation.cpp"
#include "drawable.cpp"

class Skin {
    public:
        Skin() {
            animations = NULL;
            animationIndex = 0;
        }

        void SetAnimations(Animation animations[]) {
            this->animations = animations;
        }

        Drawable GetDrawable() {
            return animationPlayer.GetDrawable();
        }

        void SetAnimationIndex(int index) {
            animationIndex = index;
        }

        void Update(unsigned int timeDelta) {
            animationPlayer.SetAnimation(&this->animations[animationIndex]);
            animationPlayer.Update(timeDelta);
        }

    private:
        Animation* animations;
        AnimationPlayer animationPlayer;
        int animationIndex;
};

#endif // SKIN_CPP
