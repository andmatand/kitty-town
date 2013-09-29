#include "animation.hpp"

AnimationPlayer::AnimationPlayer() {
    animation = NULL;
    currentFrameIndex = 0;
    frameTimer = 0;
}

Drawable* AnimationPlayer::GetDrawable() {
    Drawable* drawable = new Drawable;
    drawable->rect = &animation->frames[currentFrameIndex].rect;
    drawable->texture = animation->texture;

    return drawable;
}

void AnimationPlayer::SetAnimation(Animation* animation) {
    this->animation = animation;
    currentFrameIndex = 0;
}

void AnimationPlayer::Update() {
    if (animation == NULL) return;

    frameTimer++;

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
