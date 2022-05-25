//
// Created by rafibz007 on 18.05.22.
//

#include <cmath>
#include "Enemy.h"
#include "../Bullet/Bullet.h"
#include "../../Screens/ScreenManager.h"

int Enemy::objectsAmount = 0;
const float Enemy::DYING_TIME = 0.2;
const float Enemy::SHOT_DELAY = 1;
const float Enemy::HITBOX_HEIGHT = 60;
const float Enemy::HITBOX_WIDTH = 50;
const int Enemy::EXPLOSION_FRAMES = 8;

void Enemy::Update() {
    if (!_isDying){
        x+=enemyLogic.dx();
        y+=enemyLogic.dy();
        secondsSincePrevShot += GetFrameTime();
        if (secondsSincePrevShot >= SHOT_DELAY){
            secondsSincePrevShot = 0;
            if (enemyLogic.willShoot())
                shot();
        }
    } else {
        dyingTime += GetFrameTime();
        if (dyingTime >= DYING_TIME)
            _isDead = true;
    }
}

void Enemy::Draw() {
    float xDiff = textureSize.x - HITBOX_WIDTH;
    float yDiff = textureSize.y - HITBOX_HEIGHT;

    if (!_isDying){

//        DrawRectangle(x, y, width, height, RED);
        DrawTexture(*texture, x-xDiff/2, y-yDiff/2, WHITE);
    } else {
//        DrawRectangle(x, y, width, height, BLUE);
        int explosionFrame = std::floor((EXPLOSION_FRAMES+1)*(dyingTime/DYING_TIME));
        if (explosionFrame <= 4)
            DrawTexture(*texture, x-xDiff/2, y-yDiff/2, WHITE);

        float xExplosionDiff = explosionTextureSize.x/8 - HITBOX_WIDTH;
        float yExplosionDiff = explosionTextureSize.y - HITBOX_HEIGHT;

        DrawTextureRec(*explosionTexture,
                       Rectangle{(explosionTextureSize.x/8)*(float)explosionFrame,0,explosionTextureSize.x/8, explosionTextureSize.y},
                       Vector2{static_cast<float>(x-xExplosionDiff/2), static_cast<float>(y-yExplosionDiff/2)},
                       WHITE);
    }
}

void Enemy::shot() {
    auto* bullet = new Bullet(x-30, y+height/2-Bullet::HITBOX_HEIGHT, false, -Bullet::SPEED_X);
    Game* game = ScreenManager::GetInstance()->getGame();
    if (game != nullptr){
        game->addBullet(bullet);
        musicPlayer->playSound(SoundEnum::ENEMY_SHOOT);
    }
}

void Enemy::die() {
    _isCollidable = false;
    _isDying = true;
    musicPlayer->playSound(SoundEnum::ENEMY_HIT);
}
