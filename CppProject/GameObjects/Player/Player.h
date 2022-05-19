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

    void Draw() override {
        DrawRectangle(x, y, width, height, GREEN);
    };

private:
    void shot();


private:
    TextureHolder* textureHolder{TextureHolder::GetInstance()};
    MusicPlayer* musicPlayer{MusicPlayer::GetInstance()};
    int lives;
    static const float VERTICAL_SPEED;
    static const float HORIZONTAL_SPEED;
    static const float SHOT_DELAY;
    float secondsSincePrevShot;
    static const float HITBOX_WIDTH;
    static const float HITBOX_HEIGHT;
};


#endif //CPPPROJECT_PLAYER_H
