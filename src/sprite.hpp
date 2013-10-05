#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <vector>

#include "camera.hpp"
#include "drawable.hpp"
#include "position.hpp"
#include "size.hpp"
#include "skin.hpp"

class Room;

class Sprite {
    public:
        Sprite();
        virtual ~Sprite();

        // Comparison functions For draw-order sorting 
        bool operator< (const Sprite& rhs) const {
            return position.y + size.h < rhs.position.y + rhs.size.h;
        }
        struct PointerCompare {
            bool operator()(const Sprite* l, const Sprite* r) {
                return *l < *r;
            }
        };

        void Draw(Camera);
        Position GetPosition() { return position; };
        Size GetSize() { return size; };
        Skin* GetSkin() { return skin; };
        bool IsMirrored() { return isMirrored; };
        void SetPosition(int x, int y);
        void SetRoom(Room* room) { this->room = room; };
        virtual void Update();

        // Virtual methods for PhysicsBody
        virtual void Move(std::vector<Sprite*>*);
        virtual void PostMove();

    protected:
        bool isMirrored;
        Position position;
        Room* room;
        Size size;
        Skin* skin;
};

#endif // SPRITE_HPP
