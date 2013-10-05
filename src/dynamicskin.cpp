#include "dynamicskin.hpp"

DynamicSkin::DynamicSkin() : animations(ANIMATIONS), animationIndex(-1) {
}

DynamicSkin::~DynamicSkin() {
    //animationPlayer.Destroy();
}

//void DynamicSkin::SetAnimations(Animation* animations) {
//    this->animations = animations;
//}

CollisionMask* DynamicSkin::GetCollisionMask() {
    if (animationIndex != -1) {
        return animationPlayer.GetCollisionMask();
    }
    else {
        return NULL;
    }
}

Drawable* DynamicSkin::GetDrawable() {
    if (animationIndex != -1) {
        return animationPlayer.GetDrawable();
    }
    else {
        return NULL;
    }
}

void DynamicSkin::SetCurrentAnimation(int index) {
    if (index == animationIndex) return;

    animationIndex = index;
    animationPlayer.SetAnimation(&this->animations[animationIndex]);
}

void DynamicSkin::Update() {
    if (animationIndex != -1) {
        animationPlayer.Update();
    }
}
