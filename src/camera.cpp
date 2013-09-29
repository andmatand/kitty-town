#include "camera.hpp"

void Camera::CenterOn(Position objectPosition, Size objectSize) {
    position.x = (objectPosition.x + (objectSize.w / 2)) -
                 (SCREEN_W / 2);
    position.y = (objectPosition.y + (objectSize.h / 2)) -
                 (SCREEN_H / 2);
}
