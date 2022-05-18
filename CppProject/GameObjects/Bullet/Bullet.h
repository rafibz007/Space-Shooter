//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_BULLET_H
#define CPPPROJECT_BULLET_H


#include <raylib.h>
#include "../GameObject.h"

class Bullet: public GameObject {
public:

    Bullet(float _x, float _y, bool _shotByPlayer, float _speedX=SPEED_X):
        GameObject(_x, _y, HITBOX_WIDTH, HITBOX_HEIGHT, true),
        shotByPlayer{_shotByPlayer},
        speedX{_speedX}{}

    void Update() override;
    void Draw() override;

    bool isOut(){
        return x > GetScreenWidth();
    }

private:
    bool shotByPlayer;
    float speedX;

public:
    const static float SPEED_X;
    const static float HITBOX_WIDTH;
    const static float HITBOX_HEIGHT;
};


#endif //CPPPROJECT_BULLET_H
