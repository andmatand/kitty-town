#ifndef CHARACTERSKIN_HPP
#define CHARACTERSKIN_HPP

#include "dynamicskin.hpp"

enum class CHARACTER_ANIMATION_STATE {
    DEFAULT,
    WALK,
    BLINK,
    IDLE
};

class CharacterSkin : public DynamicSkin {
    public:
        CharacterSkin();
        void SetAnimationIndicies(int defaultIndex, int walkIndex = -1,
                                  int blinkIndex = -1, int idleIndex = -1);
        void SetAnimationState(CHARACTER_ANIMATION_STATE);
        void Update();

    private:
        CHARACTER_ANIMATION_STATE animationState;
        int defaultIndex;
        int walkIndex;
        int blinkIndex;
        int idleIndex;
};

#endif // CHARACTERSKIN_HPP
