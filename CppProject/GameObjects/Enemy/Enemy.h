//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_ENEMY_H
#define CPPPROJECT_ENEMY_H

#include <raylib.h>
#include "../GameObject.h"
#include "Logics/EnemyLogic.h"
#include "../../Utils/MusicPlayer.h"
#include "../../Utils/TextureHolder.h"

class Enemy: public GameObject {
public:
    Enemy(float _x, float _y, const EnemyLogic& _enemyLogic):
        GameObject(_x,_y,HITBOX_WIDTH,HITBOX_HEIGHT, true), enemyLogic{_enemyLogic}{
        objectsAmount++;
    }
    ~Enemy(){
        objectsAmount--;
    }

    static int getAmount(){
        return objectsAmount;
    }

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
    static const float SHOT_DELAY;
    static const float DYING_TIME;
    static const int EXPLOSION_FRAMES;

    EnemyLogic enemyLogic;
    static int objectsAmount;
    float dyingTime{0};
    float secondsSincePrevShot{0};
    MusicPlayer* musicPlayer{MusicPlayer::GetInstance()};
    TextureHolder* textureHolder{TextureHolder::GetInstance()};
    Texture2D* texture{textureHolder->getTexture(TextureEnum::ENEMY_SHIP)};
    Vector2 textureSize{TextureEnum::toSize(TextureEnum::ENEMY_SHIP)};
    Texture2D* explosionTexture{textureHolder->getTexture(TextureEnum::EXPLOSION)};
    Vector2 explosionTextureSize{TextureEnum::toSize(TextureEnum::EXPLOSION)};
};


#endif //CPPPROJECT_ENEMY_H
