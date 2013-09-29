#ifndef SCENERY_HPP
#define SCENERY_HPP

#include "animation.hpp"
#include "sprite.hpp"

#define NUM_HOUSE_ANIMATIONS 1
extern Animation* HOUSE_ANIMATIONS;

enum SCENERYTYPE {
    SCENERYTYPE_HOUSE1 = 0
};

class Scenery : public Sprite {
    public:
        Scenery(SCENERYTYPE);
        ~Scenery() { };
        void Update();
};

#endif // SCENERY_HPP
