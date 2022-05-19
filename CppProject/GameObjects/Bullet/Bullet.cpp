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
    float xDiff = textureSize.x/2 - HITBOX_WIDTH;
    float yDiff = textureSize.y - HITBOX_HEIGHT;
    if (!_isDying){

//        DrawRectangle(x,y,width,height,PURPLE);
        DrawTextureRec(*texture, Rectangle{0, 0, textureSize.x/2, textureSize.y}, Vector2{static_cast<float>(x)-xDiff/2,static_cast<float>(y)-yDiff/2}, WHITE);
    } else {

//        DrawRectangle(x,y,width,height,PURPLE);
        DrawTextureRec(*texture, Rectangle{textureSize.x/2, 0, textureSize.x/2, textureSize.y}, Vector2{static_cast<float>(x)-xDiff/2,static_cast<float>(y)-yDiff/2}, WHITE);
    }
}

void Bullet::die() {
    _isDying = true;
    _isCollidable = false;
}

Bullet::Bullet(float _x, float _y, bool _shotByPlayer, float _speedX):
    GameObject(_x, _y, HITBOX_WIDTH, HITBOX_HEIGHT, true),
    shotByPlayer{_shotByPlayer},
    speedX{_speedX}{

    if (shotByPlayer){
        texture = textureHolder->getTexture(TextureEnum::PLAYER_BULLET);
        textureSize = TextureEnum::toSize(TextureEnum::PLAYER_BULLET);
    } else {
        texture = textureHolder->getTexture(TextureEnum::ENEMY_BULLET);
        textureSize = TextureEnum::toSize(TextureEnum::ENEMY_BULLET);
    }
}