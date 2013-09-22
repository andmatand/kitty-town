#ifndef SPRITE_CPP
#define SPRITE_CPP

#include "skin.cpp"

struct Position {
    int x;
    int y;
};

class Sprite {
    public:
        SDL_Rect GetPosition() {
            return position;
        }

        Sprite() {
            isMirrored = false;
            position.x = 0;
            position.y = 0;
            positionDelta.x = 0;
            positionDelta.y = 0;
        }

        void Draw() {
            Drawable* drawable = this->skin.GetDrawable();

            // Make a scaled copy of the destination rect
            SDL_Rect destRect = position;
            destRect.x *= GRAPHICS_SCALE;
            destRect.y *= GRAPHICS_SCALE;
            destRect.w *= GRAPHICS_SCALE;
            destRect.h *= GRAPHICS_SCALE;

            SDL_RenderCopyEx(RENDERER, drawable->texture,
                             drawable->rect, &destRect,
                             0, NULL,
                             (isMirrored ?
                              SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE));

            delete drawable;
        }

        void DoPhysics() {
            position.x += positionDelta.x;
            position.y += positionDelta.y;
        }

        void Update() {
            skin.Update();
        }

        void DoPostPhysics() {
            positionDelta.x = 0;
            positionDelta.y = 0;
        }

    protected:
        bool isMirrored;
        SDL_Rect position;
        Position positionDelta;
        Skin skin;
};

#endif // SPRITE_CPP
