#include "sprite.hpp"

Sprite::Sprite() : isMirrored(false), skin(NULL) {
}

Sprite::~Sprite() {
    delete skin;
    skin = NULL;
}

void Sprite::Draw(Camera camera) {
    Drawable* drawable = skin->GetDrawable();
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

    SDL_RenderCopyEx(RENDERER,
                     drawable->texture,
                     drawable->rect,
                     &destRect,
                     0,
                     NULL,
                     (isMirrored ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE));
}

void Sprite::SetPosition(int x, int y) {
    position.x = x; position.y = y;
}

void Sprite::Update() {
}

// Virtual methods for PhysicsBody
void Sprite::Move(std::vector<Sprite*>*) {}
void Sprite::PostMove() {}
