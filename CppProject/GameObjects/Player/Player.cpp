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

void Player::Update() {
    //        MOVE PLAYER
    if (IsKeyDown(KEY_W))
        y -= VERTICAL_SPEED * GetFrameTime();

    if (IsKeyDown(KEY_S))
        y += VERTICAL_SPEED * GetFrameTime();

    if (IsKeyDown(KEY_A))
        x -= HORIZONTAL_SPEED * GetFrameTime();

    if (IsKeyDown(KEY_D))
        x += HORIZONTAL_SPEED * GetFrameTime();

//        PREVENT GOING OUT OF SCREEN
    if (x<0)
        x = 0;
    else if (x+width>GetScreenWidth())
        x=GetScreenWidth()-width;

    if (y<0)
        y = 0;
    else if (y+height>GetScreenHeight())
        y=GetScreenHeight()-height;

//        SHOOT IF SPACE PRESSED
    secondsSincePrevShot = std::min(secondsSincePrevShot + GetFrameTime(), SHOT_DELAY);
    if (secondsSincePrevShot >= SHOT_DELAY && IsKeyDown(KEY_SPACE)){
        secondsSincePrevShot = 0;
        shot();
    }

}
