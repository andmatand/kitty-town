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

            SDL_RenderCopy(RENDERER, drawable->texture, drawable->rect,
                           &destRect);

            delete drawable;
        }

        void DoPhysics() {
            position.x += positionDelta.x;
            position.y += positionDelta.y;
        }

        void Update(unsigned int timeDelta) {
            skin.Update(timeDelta);
        }

        void DoPostPhysics() {
            positionDelta.x = 0;
            positionDelta.y = 0;
        }

    protected:
        SDL_Rect position;
        Position positionDelta;
        Skin skin;
};

#endif // SPRITE_CPP
