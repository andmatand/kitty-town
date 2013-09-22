#ifndef SPRITE_CPP
#define SPRITE_CPP

#include "camera.cpp"
#include "skin.cpp"

class Sprite {
    public:
        Sprite() {
            isMirrored = false;
            position.x = 0;
            position.y = 0;
            positionDelta.x = 0;
            positionDelta.y = 0;
            size.w = 0;
            size.h = 0;
        }

        void Draw(Camera camera) {
            Drawable* drawable = this->skin.GetDrawable();

            // Make a destination rect based on our position and size
            SDL_Rect destRect;
            destRect.x = position.x;
            destRect.y = position.y;
            destRect.w = size.w;
            destRect.h = size.h;

            // Offest the destination rect based on the camera's position
            Position cameraPosition = camera.GetPosition();
            destRect.x -= cameraPosition.x;
            destRect.y -= cameraPosition.y;

            // Scale the destination rect based on the current graphics scale
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

        Position GetPosition() {
            return position;
        }

        Size GetSize() {
            return size;
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
        Position position;
        Size size;
        Position positionDelta;
        Skin skin;
};

#endif // SPRITE_CPP
