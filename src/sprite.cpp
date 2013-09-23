#ifndef SPRITE_CPP
#define SPRITE_CPP

#include "camera.cpp"
#include "skin.cpp"

using namespace std;

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

        virtual ~Sprite() {
        }

        // Comparison functions For draw-order sorting 
        bool operator< (const Sprite& rhs) const {
            return position.y < rhs.position.y;
        }
        struct PointerCompare {
            bool operator()(const Sprite* l, const Sprite* r) {
                return *l < *r;
            }
        };

        void Draw(Camera camera) {
            Drawable* drawable = this->skin.GetDrawable();
            if (drawable == NULL) return;

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

        void DoPhysics(vector<Sprite*>* otherSprites) {
            if (positionDelta.x == 0 && positionDelta.y == 0) return;

            Position destination;
            destination.x = position.x + positionDelta.x;
            destination.y = position.y + positionDelta.y;

            Position tempPosition = position;

            int xIncrement = 0;
            if (tempPosition.x < destination.x) {
                xIncrement = 1;
            }
            else if (tempPosition.x > destination.x) {
                xIncrement = -1;
            }

            int yIncrement = 0;
            if (tempPosition.y < destination.y) {
                yIncrement = 1;
            }
            else if (tempPosition.y > destination.y) {
                yIncrement = -1;
            }

            // Loop until we reach our destination
            Position previousPosition;
            bool collided = false;
            while (tempPosition.x != destination.x ||
                   tempPosition.y != destination.y) {
                //previousPosition = tempPosition;
                previousPosition.x = tempPosition.x;
                previousPosition.y = tempPosition.y;
                tempPosition.x += xIncrement;
                tempPosition.y += yIncrement;

                for (vector<Sprite*>::iterator otherSprite =
                     (*otherSprites).begin();
                     otherSprite != (*otherSprites).end(); otherSprite++) {
                    // If this otherSprite is not us
                    if (static_cast<Sprite*>(*otherSprite) != this) {
                        if (RectCollision(tempPosition,
                                          this->GetSize(),
                                          (*otherSprite)->GetPosition(),
                                          (*otherSprite)->GetSize())) {
                            collided = true;
                            break;
                        }
                    }
                }

                if (collided) {
                    tempPosition = previousPosition;
                    break;
                }
            }
            position = tempPosition;
        }

        static bool RectCollision(Position position1, Size size1,
                                  Position position2, Size size2) {
            //if ((position1.x <= position2.x + (size2.w - 1) &&
            //     position1.x + (size1.w - 1) >= position2.x) &&
            //    (position1.y <= position2.y + (size2.h - 1) &&
            //     position1.y + (size1.h - 1) >= position2.y)) {
            //    return true;
            //}

            if ((position1.x <= position2.x + (size2.w - 1) &&
                 position1.x + (size1.w - 1) >= position2.x) &&
                (position1.y <= position2.y + (size2.h / 2) &&
                 position1.y + (size1.h / 2) >= position2.y)) {
                return true;
            }

            return false;
        }

        void DoPostPhysics() {
            positionDelta.x = 0;
            positionDelta.y = 0;
        }

        Position GetPosition() {
            return position;
        }

        Size GetSize() {
            return size;
        }

        void SetPosition(int x, int y) {
            position.x = x;
            position.y = y;
        }

        virtual void Update() {
        }

    protected:
        bool isMirrored;
        Position position;
        Position positionDelta;
        Size size;
        Skin skin;
};

#endif // SPRITE_CPP
