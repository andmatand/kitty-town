#include "character.hpp"

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
    if (positionDelta.x != 0 || positionDelta.y != 0) {
        // Switch to walking animation
        skin.SetCurrentAnimation(1);
    }
    else {
        skin.SetCurrentAnimation(0);
    }

    skin.Update();
}
