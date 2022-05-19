//
// Created by rafibz007 on 18.05.22.
//

#include "Player.h"
#include "../Bullet/Bullet.h"
#include "../../Screens/ScreenManager.h"

float const Player::VERTICAL_SPEED = 500;
float const Player::HORIZONTAL_SPEED = 450;
float const Player::HITBOX_HEIGHT = 50;
float const Player::HITBOX_WIDTH = 75;
float const Player::SHOT_DELAY = 0.5;

void Player::shot() {
    auto* bullet = new Bullet(x+width, y+height/2-Bullet::HITBOX_HEIGHT, true);
    Game* game = ScreenManager::GetInstance()->getGame();
    if (game != nullptr)
        game->addBullet(bullet);
}
