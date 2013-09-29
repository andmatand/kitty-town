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

        void DoPhysics(std::vector<Sprite*>*);
        void DoPostPhysics();
        void Draw(Camera);
        Position GetPosition() { return position; };
        Size GetSize() { return size; };
        static bool RectCollision(Position, Size, Position, Size);
        void SetPosition(int x, int y) { position.x = x; position.y = y; };
        void SetRoom(Room* room) { this->room = room; };
        virtual void Update();

    protected:
        bool isMirrored;
        Position position;
        Position positionDelta;
        Room* room;
        Size size;
        Skin skin;
};

#endif // SPRITE_HPP
