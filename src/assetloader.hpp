#ifndef ASSETLOADER_HPP
#define ASSETLOADER_HPP

#include <SDL2/SDL.h>
#include "animation.hpp"
#include "collisionmask.hpp"
#include "globals.hpp"

#define NUM_SPRITE_RECTS 5
#define NUM_COLLISION_MASKS 1
#define NUM_ANIMATIONS 2

namespace AssetLoader {
    void LoadEverything();
    void DestroyEverything();

    void InitAnimations();
    void DestroyAnimations();
    
    void InitCollisionMaskRects();
    void DestroyCollisionMaskRects();

    void InitCollisionMasks();
    void DestroyCollisionMasks();

    void InitTextures();
    void DestroyTextures();

    void InitSpriteRects();
    void DestroySpriteRects();
}

#endif // ASSETLOADER_HPP
