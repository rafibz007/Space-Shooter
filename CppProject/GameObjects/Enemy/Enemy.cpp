//
// Created by rafibz007 on 18.05.22.
//

#include "Enemy.h"
#include "../Bullet/Bullet.h"
#include "../../Screens/ScreenManager.h"

const float Enemy::DYING_TIME = 0.2;
const float Enemy::SHOT_DELAY = 1;
const float Enemy::HITBOX_HEIGHT = 70;
const float Enemy::HITBOX_WIDTH = 60;

void Enemy::Update() {
    if (!_isDying){
        x+=enemyLogic.dx();
        y+=enemyLogic.dy();
        secondsSincePrevShot += GetFrameTime();
        if (secondsSincePrevShot >= SHOT_DELAY){
            secondsSincePrevShot = 0;
            shot();
        }
    } else {
        dyingTime += GetFrameTime();
        if (dyingTime >= DYING_TIME)
            _isDead = true;
    }
}

void Enemy::Draw() {
    if (!_isDying)
        DrawRectangle(x, y, width, height, RED);
    else
        DrawRectangle(x, y, width, height, BLUE);
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
