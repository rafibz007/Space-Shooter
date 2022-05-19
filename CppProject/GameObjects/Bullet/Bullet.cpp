//
// Created by rafibz007 on 18.05.22.
//

#include "Bullet.h"

const float Bullet::SPEED_X = 600;
const float Bullet::HITBOX_HEIGHT = 10;
const float Bullet::HITBOX_WIDTH = 30;
const float Bullet::DYING_TIME = 0.1;

void Bullet::Update() {
    if (!_isDying){
        x += speedX * GetFrameTime();
    } else {
        dyingTime += GetFrameTime();
        if (dyingTime >= DYING_TIME)
            _isDead = true;
    }
}

void Bullet::Draw() {
    if (!_isDying){
        if (shotByPlayer)
            DrawRectangle(x,y,width,height,YELLOW);
        else
            DrawRectangle(x,y,width,height,WHITE);
    } else {
        if (shotByPlayer)
            DrawRectangle(x,y,width,height,PURPLE);
        else
            DrawRectangle(x,y,width,height,GRAY);
    }
}

void Bullet::die() {
    _isDying = true;
    _isCollidable = false;
}
