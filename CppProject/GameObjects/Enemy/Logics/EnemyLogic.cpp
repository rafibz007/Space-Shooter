//
// Created by rafibz007 on 18.05.22.
//

#include <raylib.h>
#include "EnemyLogic.h"

void EnemyLogic::Update() {
    speedX += accX*GetFrameTime();
    speedY += accY*GetFrameTime();
}

float EnemyLogic::dx() {
    return speedX*GetFrameTime();
}

float EnemyLogic::dy() {
    return speedY*GetFrameTime();
}

bool EnemyLogic::willShoot() {
    return true;
}
