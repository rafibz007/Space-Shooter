//
// Created by rafibz007 on 18.05.22.
//

#include "Bullet.h"

const float Bullet::SPEED_X = 100;

void Bullet::Update() {
    x += SPEED_X * GetFrameTime();
}

void Bullet::Draw() {
    DrawRectangle(x,y,width,height,YELLOW);
}
