#ifndef ANIMATION_CPP
#define ANIMATION_CPP

#include "drawable.cpp"

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
        AnimationPlayer() {
            animation = NULL;
            currentFrameIndex = 0;
            frameTimer = 0;
        }

        void SetAnimation(Animation* animation) {
            this->animation = animation;
        }

        Drawable* GetDrawable() {
            Drawable* drawable = new Drawable;
            drawable->rect = &animation->frames[currentFrameIndex].rect;
            drawable->texture = animation->texture;

            return drawable;
        }

        void Update(unsigned int timeDelta) {
            if (animation == NULL) return;

            frameTimer += timeDelta;

            if (frameTimer >= animation->frames[currentFrameIndex].delay) {
                frameTimer = 0;

                if (currentFrameIndex < animation->numFrames - 1) {
                    currentFrameIndex++;
                }
                else {
                    if (animation->loop) {
                        currentFrameIndex = 0;
                    }
                }
            }
        }

    private:
        Animation* animation;
        int currentFrameIndex;
        unsigned int frameTimer;
};

#endif // ANIMATION_CPP
