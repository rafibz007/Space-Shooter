//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_PLAYER_H
#define CPPPROJECT_PLAYER_H


#include <raylib.h>
#include <iostream>
#include "../GameObject.h"
#include "../Bullet/Bullet.h"


class Player: public GameObject {
public:
    explicit Player(int _lives=3):
        GameObject(10, (GetScreenHeight()-HITBOX_HEIGHT)/2, HITBOX_WIDTH, HITBOX_HEIGHT, true),
        lives{_lives},
        secondsSincePrevShot{SHOT_DELAY}{}

    void receiveDamage(){
        lives--;
    }

    bool hasLives() const {
        return lives>0;
    }

    int getLives() const {
        return lives;
    }

    void Update() override {
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

    };

    void Draw() override {
        DrawRectangle(x, y, width, height, GREEN);
    };

private:
    void shot();


private:
    int lives;
    static const float VERTICAL_SPEED;
    static const float HORIZONTAL_SPEED;
    static const float SHOT_DELAY;
    float secondsSincePrevShot;
    static const float HITBOX_WIDTH;
    static const float HITBOX_HEIGHT;
};


#endif //CPPPROJECT_PLAYER_H
