#ifndef SKIN_CPP
#define SKIN_CPP

#include "animation.cpp"
#include "drawable.cpp"

class Skin {
    public:
        Skin() {
            animations = NULL;
            animationIndex = -1;
        }

        void SetAnimations(Animation* animations) {
            this->animations = animations;
        }

        Drawable* GetDrawable() {
            if (animationIndex != -1) {
                return animationPlayer.GetDrawable();
            }
            else {
                return NULL;
            }
        }

        void SetCurrentAnimation(int index) {
            if (index == animationIndex) return;

            animationIndex = index;
            animationPlayer.SetAnimation(&this->animations[animationIndex]);
        }

        void Update() {
            if (animationIndex != -1) {
                animationPlayer.Update();
            }
        }

    private:
        Animation* animations;
        AnimationPlayer animationPlayer;
        int animationIndex;
};

#endif // SKIN_CPP
