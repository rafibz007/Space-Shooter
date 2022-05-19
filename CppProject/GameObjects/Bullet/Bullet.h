//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_BULLET_H
#define CPPPROJECT_BULLET_H


#include <raylib.h>
#include "../GameObject.h"
#include "../../Utils/TextureHolder.h"

class Bullet: public GameObject {
public:

    Bullet(float _x, float _y, bool _shotByPlayer, float _speedX=SPEED_X);

    void Update() override;
    void Draw() override;

    bool isOut(){
        return x > GetScreenWidth() || x+width < 0;
    }

    bool isPlayerBullet() const{
        return shotByPlayer;
    }

    void die() override;

private:
    bool shotByPlayer;
    float speedX;

public:
    const static float SPEED_X;
    const static float HITBOX_WIDTH;
    const static float HITBOX_HEIGHT;
    static const float DYING_TIME;
    float dyingTime{0};
    TextureHolder* textureHolder{TextureHolder::GetInstance()};
    Texture2D* texture{};
    Vector2 textureSize{};
};


#endif //CPPPROJECT_BULLET_H
