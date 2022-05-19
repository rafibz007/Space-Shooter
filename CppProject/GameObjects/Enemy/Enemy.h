//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_ENEMY_H
#define CPPPROJECT_ENEMY_H

#include <raylib.h>
#include "../GameObject.h"
#include "Logics/EnemyLogic.h"
#include "../../Utils/MusicPlayer.h"

class Enemy: public GameObject {
public:
    Enemy(float _x, float _y, const EnemyLogic& _enemyLogic):
        GameObject(_x,_y,HITBOX_WIDTH,HITBOX_HEIGHT, true), enemyLogic{_enemyLogic}{}

    void Update() override;
    void Draw() override;

    bool isOut(){
        return x+width<0;
    }

    void die() override;

private:
    void shot();

public:
    static const float HITBOX_WIDTH;
    static const float HITBOX_HEIGHT;

private:
    EnemyLogic enemyLogic;
    static const float SHOT_DELAY;
    static const float DYING_TIME;
    float dyingTime{0};
    float secondsSincePrevShot;
    MusicPlayer* musicPlayer{MusicPlayer::GetInstance()};
};


#endif //CPPPROJECT_ENEMY_H
