#include "scenery.hpp"

Animation* HOUSE_ANIMATIONS = new Animation[NUM_HOUSE_ANIMATIONS];

Scenery::Scenery(SCENERYTYPE type) {
    switch (type) {
       case SCENERYTYPE_HOUSE1:
           skin.SetAnimations(HOUSE_ANIMATIONS);
           skin.SetCurrentAnimation(0);
           size.w = HOUSE_ANIMATIONS[0].frames[0].rect.w;
           size.h = HOUSE_ANIMATIONS[0].frames[0].rect.h;
           break;
   }
}

void Scenery::Update() {
    skin.Update();
}
