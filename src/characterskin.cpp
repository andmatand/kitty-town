#include "characterskin.hpp"

CharacterSkin::CharacterSkin() : defaultIndex(-1),
                                      walkIndex(-1),
                                      blinkIndex(-1),
                                      idleIndex(-1) {
}

void CharacterSkin::SetAnimationIndicies(int defaultIndex, int walkIndex,
                                         int blinkIndex, int idleIndex) {
    this->defaultIndex = defaultIndex;
    this->walkIndex = walkIndex;
    this->blinkIndex = blinkIndex;
    this->idleIndex = idleIndex;
}

void CharacterSkin::SetAnimationState(CHARACTER_ANIMATION_STATE state) {
    animationState = state;
}

void CharacterSkin::Update() {
    switch (animationState) {
        case CHARACTER_ANIMATION_STATE::WALK:
            SetCurrentAnimation(1);
            break;
        default:
            SetCurrentAnimation(0);
    }

    DynamicSkin::Update();
}
