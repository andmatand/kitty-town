#include "physicsbody.hpp"

void PhysicsBody::Move(std::vector<Sprite*>* collidableSprites) {
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

        for (std::vector<Sprite*>::iterator sprite =
             (*collidableSprites).begin();
             sprite != (*collidableSprites).end(); sprite++) {
            // If this sprite is not us
            if ((*sprite) != this) {
                if (IsCollision(this, tempPosition, *sprite)) {
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

void PhysicsBody::PostMove() {
    positionDelta.x = 0;
    positionDelta.y = 0;
}

bool PhysicsBody::IsCollision(Sprite* sprite1, Position sprite1Position,
                                  Sprite* sprite2) {
    if (CollisionMask::IsMaskCollision(sprite1->GetSkin()->GetCollisionMask(),
                                       sprite1Position,
                                       sprite1->IsMirrored(),
                                       false,
                                       sprite2->GetSkin()->GetCollisionMask(),
                                       sprite2->GetPosition(),
                                       sprite2->IsMirrored(),
                                       false)) {
        return true;
    }
    else {
        return false;
    }
}
