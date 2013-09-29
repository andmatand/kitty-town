#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "globals.hpp"
#include "position.hpp"
#include "size.hpp"

class Camera {
    public:
        void CenterOn(Position, Size);
        Position GetPosition() { return position; };

    private:
        Position position;
};

#endif // CAMERA_HPP
