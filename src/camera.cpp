#ifndef CAMERA_CPP
#define CAMERA_CPP

class Camera {
    public:
        void CenterOn(Position objectPosition, Size objectSize) {
            position.x = (objectPosition.x + (objectSize.w / 2)) -
                         (SCREEN_W / 2);
            position.y = (objectPosition.y + (objectSize.h / 2)) -
                         (SCREEN_H / 2);
        }

        Position GetPosition() {
            return position;
        }

    private:
        Position position;
};

#endif // CAMERA_CPP
