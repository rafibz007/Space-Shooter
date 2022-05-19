//
// Created by rafibz007 on 18.05.22.
//

#include "Bullet.h"

const float Bullet::SPEED_X = 600;
const float Bullet::HITBOX_HEIGHT = 10;
const float Bullet::HITBOX_WIDTH = 30;

void Bullet::Update() {
    x += speedX * GetFrameTime();
}

void Bullet::Draw() {
    if (shotByPlayer)
        DrawRectangle(x,y,width,height,YELLOW);
    else
        DrawRectangle(x,y,width,height,WHITE);
}
