#ifndef FIXTURE_HPP
#define FIXTURE_HPP

#include <SDL2/SDL.h>
#include "globals.hpp"
#include "sprite.hpp"
#include "staticskin.hpp"

enum class FIXTURE_TYPE {
    HOUSE1
};

class Fixture : public Sprite {
    public:
        Fixture(FIXTURE_TYPE fixtureType);
};

#endif // FIXTURE_HPP
