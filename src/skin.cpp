#include "skin.hpp"

Skin::Skin() : animations(NULL), animationIndex(-1) {};

void Skin::SetAnimations(Animation* animations) {
    this->animations = animations;
}

Drawable* Skin::GetDrawable() {
    if (animationIndex != -1) {
        return animationPlayer.GetDrawable();
    }
    else {
        return NULL;
    }
}

void Skin::SetCurrentAnimation(int index) {
    if (index == animationIndex) return;

    animationIndex = index;
    animationPlayer.SetAnimation(&this->animations[animationIndex]);
}

void Skin::Update() {
    if (animationIndex != -1) {
        animationPlayer.Update();
    }
}
