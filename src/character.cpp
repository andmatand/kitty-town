#include "character.hpp"

Character::Character() {
    skin = new CharacterSkin();
}

void Character::KeyPressed(KEY key) {
    if (key == KEY_LEFT) {
        if (isMirrored) {
            isMirrored = false;
        }
        else {
            positionDelta.x = -1;
        }
    }
    else if (key == KEY_RIGHT) {
        if (!isMirrored) {
            isMirrored = true;
        }
        else {
            positionDelta.x = 1;
        }
    }
    else if (key == KEY_UP) {
        positionDelta.y = -1;
    }
    else if (key == KEY_DOWN) {
        positionDelta.y = 1;
    }
}

void Character::Update() {
    CharacterSkin* skin = static_cast<CharacterSkin*>(this->skin);

    if (positionDelta.x != 0 || positionDelta.y != 0) {
        skin->SetAnimationState(CHARACTER_ANIMATION_STATE::WALK);
    }
    else {
        skin->SetAnimationState(CHARACTER_ANIMATION_STATE::DEFAULT);
    }

    skin->Update();
}
