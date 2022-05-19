//
// Created by rafibz007 on 18.05.22.
//

#include "GameObject.h"

bool GameObject::hasCollision(const GameObject &gameObject) {
    return this->isCollidable() && gameObject.isCollidable() &&
            this->x < gameObject.x + gameObject.width &&
            this->x + this->width > gameObject.x &&
            this->y < gameObject.y + gameObject.height &&
            this->height + this->y > gameObject.y;
}
