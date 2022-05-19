//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_PLAYER_H
#define CPPPROJECT_PLAYER_H


#include <raylib.h>
#include <iostream>
#include "../GameObject.h"
#include "../Bullet/Bullet.h"
#include "../../Utils/TextureHolder.h"
#include "../../Utils/MusicPlayer.h"


class Player: public GameObject {
public:
    explicit Player(int _lives=3):
        GameObject(10, (GetScreenHeight()-HITBOX_HEIGHT)/2, HITBOX_WIDTH, HITBOX_HEIGHT, true),
        lives{_lives},
        secondsSincePrevShot{SHOT_DELAY}{}

    void receiveDamage(){
        lives--;
        musicPlayer->playSound(SoundEnum::PLAYER_HIT);
    }

    bool hasLives() const {
        return lives>0;
    }

    int getLives() const {
        return lives;
    }

    void die() override;

    void Update() override;

    void Draw() override;

private:
    void shot();


private:
    TextureHolder* textureHolder{TextureHolder::GetInstance()};
    MusicPlayer* musicPlayer{MusicPlayer::GetInstance()};
    Texture2D* texture{textureHolder->getTexture(TextureEnum::PLAYER_SHIP)};
    Vector2 textureSize{TextureEnum::toSize(TextureEnum::PLAYER_SHIP)};
    Texture2D* explosionTexture{textureHolder->getTexture(TextureEnum::EXPLOSION)};
    Vector2 explosionTextureSize{TextureEnum::toSize(TextureEnum::EXPLOSION)};
    int lives;
    static const float VERTICAL_SPEED;
    static const float HORIZONTAL_SPEED;
    static const float SHOT_DELAY;
    float secondsSincePrevShot;
    static const float HITBOX_WIDTH;
    static const float HITBOX_HEIGHT;
    static const float DYING_TIME;
    static const int EXPLOSION_FRAMES;
    float dyingTime{0};
};


#endif //CPPPROJECT_PLAYER_H
