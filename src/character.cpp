#ifndef CHARACTER_CPP
#define CHARACTER_CPP

#include "sprite.cpp"

class Character : public Sprite {
    public:
        void KeyPressed(KEY key) {
            if (key == KEY_LEFT) {
                positionDelta.x = -1;
            }
            else if (key == KEY_RIGHT) {
                positionDelta.x = 1;
            }
            else if (key == KEY_UP) {
                positionDelta.y = -1;
            }
            else if (key == KEY_DOWN) {
                positionDelta.y = 1;
            }
        }

        void Update(unsigned int timeDelta) {
            std::cout << "character update\n";

            if (positionDelta.x != 0 || positionDelta.y != 0) {
                // Switch to walking animation
                skin.SwitchToAnimation(1);
            }
            else {
                skin.SwitchToAnimation(0);
            }

            // Call the superclass's Update()
            Sprite::Update(timeDelta);
        }
};

#endif // CHARACTER_CPP
