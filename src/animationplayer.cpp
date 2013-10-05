#include "animationplayer.hpp"

AnimationPlayer::AnimationPlayer() {
    animation = NULL;
    currentFrameIndex = 0;
    frameTimer = 0;
    drawable = new Drawable();
}

AnimationPlayer::~AnimationPlayer() {
    delete drawable;
    drawable = NULL;
}

CollisionMask* AnimationPlayer::GetCollisionMask() {
    return animation->frames[currentFrameIndex].collisionMask;
}

Drawable* AnimationPlayer::GetDrawable() {
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
