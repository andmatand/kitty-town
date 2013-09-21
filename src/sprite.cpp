#ifndef SPRITE_CPP
#define SPRITE_CPP

#include "skin.cpp"

class Sprite {
    public:
        SDL_Rect GetPosition();
        Skin GetSkin();

        Sprite() {
            position.x = 0;
            position.y = 0;
        }

        void Draw() {
            Drawable drawable = this->skin.GetDrawable();

            //std::cout << "drawable rect x:" << drawable.rect->x << std::endl;
            //std::cout << "drawable rect y:" << drawable.rect->y << std::endl;
            //std::cout << "drawable rect w:" << drawable.rect->w << std::endl;
            //std::cout << "drawable rect h:" << drawable.rect->h << std::endl;
            //std::cout << "drawable texture:" << drawable.texture << std::endl;

            //std::cout << "position x:" << position.x << std::endl;
            //std::cout << "position y:" << position.y << std::endl;
            //std::cout << "position w:" << position.w << std::endl;
            //std::cout << "position h:" << position.h << std::endl;

            SDL_RenderCopy(RENDERER, drawable.texture, drawable.rect,
                           &this->position);
        }

        void Update(unsigned int timeDelta) {
            skin.Update(timeDelta);
        }

    protected:
        Skin skin;
        SDL_Rect position;
};

#endif // SPRITE_CPP
