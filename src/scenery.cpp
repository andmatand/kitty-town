#ifndef SCENERY_CPP
#define SCENERY_CPP

#include "animation.cpp"
#include "sprite.cpp"

#define NUM_HOUSE_ANIMATIONS 1
Animation* HOUSE_ANIMATIONS;

enum SCENERYTYPE {
    SCENERYTYPE_HOUSE1 = 0
};

class Scenery : public Sprite {
    public:
        Scenery(SCENERYTYPE type) {
           switch (type) {
               case SCENERYTYPE_HOUSE1:
                   skin.SetAnimations(HOUSE_ANIMATIONS);
                   skin.SetCurrentAnimation(0);
                   size.w = HOUSE_ANIMATIONS[0].frames[0].rect.w;
                   size.h = HOUSE_ANIMATIONS[0].frames[0].rect.h;
                   break;
           }
        }

        ~Scenery() {
        }

        void Update() {
            skin.Update();
        }
};

#endif // SCENERY_CPP
