#include "assetloader.hpp"

// DEBUG
#include <iostream>

namespace AssetLoader {
    void LoadEverything() {
        std::cout << "Loading textures...";
        InitTextures();
        std::cout << "done\n";

        std::cout << "Defining collision mask rects...";
        InitCollisionMaskRects();
        std::cout << "done\n";

        std::cout << "Initializing collision masks...";
        InitCollisionMasks();
        std::cout << "done\n";

        std::cout << "Defining sprite rects...";
        InitSpriteRects();
        std::cout << "done\n";

        std::cout << "Defining animations...";
        InitAnimations();
        std::cout << "done\n";
    }

    void DestroyEverything() {
        DestroyAnimations();
        DestroySpriteRects();

        DestroyCollisionMasks();
        DestroyCollisionMaskRects();

        DestroyTextures();
    }

    void DestroyAnimations() {
        for (int i = 0; i < NUM_ANIMATIONS; i++) {
            delete [] ANIMATIONS[i].frames;
        }
    }

    void DestroyTextures() {
        SDL_DestroyTexture(SPRITE_TEXTURE);
        SDL_DestroyTexture(BG_TEXTURE);
    }

    void DestroyCollisionMaskRects() {
        delete [] COLLISION_MASK_RECTS;
    }

    void DestroyCollisionMasks() {
        delete [] COLLISION_MASKS;
    }

    void DestroySpriteRects() {
        delete [] SPRITE_RECTS;
    }

    void InitAnimations() {
        ANIMATIONS = new Animation[NUM_ANIMATIONS];

        // kitty - default
        ANIMATIONS[0].texture = SPRITE_TEXTURE;
        ANIMATIONS[0].loop = false;
        ANIMATIONS[0].numFrames = 1;
        ANIMATIONS[0].frames = new AnimationFrame[1];
        ANIMATIONS[0].frames[0].rect = SPRITE_RECTS[0];
        ANIMATIONS[0].frames[0].delay = 0;
        ANIMATIONS[0].frames[0].collisionMask = COLLISION_MASKS[0];

        // kitty - walk
        ANIMATIONS[1].texture = SPRITE_TEXTURE;
        ANIMATIONS[1].loop = true;
        ANIMATIONS[1].numFrames = 2;
        ANIMATIONS[1].frames = new AnimationFrame[2];
        ANIMATIONS[1].frames[0].rect = SPRITE_RECTS[1];
        ANIMATIONS[1].frames[0].delay = 4;
        ANIMATIONS[1].frames[0].collisionMask = COLLISION_MASKS[0];
        ANIMATIONS[1].frames[1].rect = SPRITE_RECTS[0];
        ANIMATIONS[1].frames[1].delay = 4;
        ANIMATIONS[1].frames[1].collisionMask = COLLISION_MASKS[0];
    }

    void InitCollisionMaskRects() {
        COLLISION_MASK_RECTS = new SDL_Rect[NUM_COLLISION_MASKS];

        // kitty
        COLLISION_MASK_RECTS[0].x = 0;
        COLLISION_MASK_RECTS[0].y = 0;
        COLLISION_MASK_RECTS[0].w = 7;
        COLLISION_MASK_RECTS[0].h = 5;

        // house1
        COLLISION_MASK_RECTS[1].x = 0;
        COLLISION_MASK_RECTS[1].y = 5;
        COLLISION_MASK_RECTS[1].w = 21;
        COLLISION_MASK_RECTS[1].h = 15;
    }

    void InitCollisionMasks() {
        COLLISION_MASKS = new CollisionMask*[NUM_COLLISION_MASKS];

        SDL_Surface* maskSurface = SDL_LoadBMP("res/img/collisionmasks.bmp");

        for (int i = 0; i < NUM_COLLISION_MASKS; i++) {
            COLLISION_MASKS[i] = new CollisionMask(maskSurface,
                                                   &COLLISION_MASK_RECTS[i]);
        }

        SDL_FreeSurface(maskSurface);
    }

    void InitSpriteRects() {
        SPRITE_RECTS = new SDL_Rect[NUM_SPRITE_RECTS];

        // kitty - default
        SPRITE_RECTS[0].x = 0;
        SPRITE_RECTS[0].y = 0;
        SPRITE_RECTS[0].w = 7;
        SPRITE_RECTS[0].h = 5;

        // kitty - walk
        SPRITE_RECTS[1].x = SPRITE_RECTS[0].w;
        SPRITE_RECTS[1].y = SPRITE_RECTS[0].y;
        SPRITE_RECTS[1].w = SPRITE_RECTS[0].w;
        SPRITE_RECTS[1].h = SPRITE_RECTS[0].h;

        // kitty - blink
        SPRITE_RECTS[2].x = SPRITE_RECTS[0].w * 2;
        SPRITE_RECTS[2].y = SPRITE_RECTS[0].y;
        SPRITE_RECTS[2].w = SPRITE_RECTS[0].w;
        SPRITE_RECTS[2].h = SPRITE_RECTS[0].h;

        // kitty - idle
        SPRITE_RECTS[3].x = SPRITE_RECTS[0].w * 3;
        SPRITE_RECTS[3].y = SPRITE_RECTS[0].y;
        SPRITE_RECTS[3].w = SPRITE_RECTS[0].w;
        SPRITE_RECTS[3].h = SPRITE_RECTS[0].h;

        // house1
        SPRITE_RECTS[4].x = 0;
        SPRITE_RECTS[4].y = 5;
        SPRITE_RECTS[4].w = 21;
        SPRITE_RECTS[4].h = 15;
    }

    void InitTextures() {
        // Load the sprite sheet
        SDL_Surface* spriteSurface = SDL_LoadBMP("res/img/sprites.bmp");
        SPRITE_TEXTURE = SDL_CreateTextureFromSurface(RENDERER, spriteSurface);
        SDL_FreeSurface(spriteSurface);

        // Load the background sheet
        SDL_Surface* bgSurface = SDL_LoadBMP("res/img/backgrounds.bmp");
        BG_TEXTURE = SDL_CreateTextureFromSurface(RENDERER, bgSurface);
        SDL_FreeSurface(bgSurface);
    }
}
