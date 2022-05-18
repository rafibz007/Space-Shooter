//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_ENEMY_H
#define CPPPROJECT_ENEMY_H


#include "../GameObject.h"

class Enemy: public GameObject {
public:
    Enemy() = default;

    void Update() override;
    void Draw() override;

};


#endif //CPPPROJECT_ENEMY_H
