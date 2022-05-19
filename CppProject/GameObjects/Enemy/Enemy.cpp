//
// Created by rafibz007 on 18.05.22.
//

#include "Enemy.h"
#include "../Bullet/Bullet.h"
#include "../../Screens/ScreenManager.h"

const float Enemy::SHOT_DELAY = 1;
const float Enemy::HITBOX_HEIGHT = 60;
const float Enemy::HITBOX_WIDTH = 90;

void Enemy::Update() {
    x+=enemyLogic.dx();
    y+=enemyLogic.dy();
    secondsSincePrevShot += GetFrameTime();
    if (secondsSincePrevShot >= SHOT_DELAY){
        secondsSincePrevShot = 0;
        shot();
    }
}

void Enemy::Draw() {
    DrawRectangle(x, y, width, height, RED);
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
    GameObject::die();
    musicPlayer->playSound(SoundEnum::ENEMY_HIT);
}
