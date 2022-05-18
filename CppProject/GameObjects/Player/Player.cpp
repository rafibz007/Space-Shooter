//
// Created by rafibz007 on 18.05.22.
//

#include "Player.h"

float const Player::VERTICAL_SPEED = 500;
float const Player::HORIZONTAL_SPEED = 450;
float const Player::HITBOX_HEIGHT = 50;
float const Player::HITBOX_WIDTH = 75;
float const Player::SHOT_DELAY = 1;

void Player::shot() {
//todo
    auto* bullet = new Bullet(x+width, y+height/2-Bullet::HITBOX_HEIGHT, true);

    std::cout<<"Shot!"<<std::endl;

}
