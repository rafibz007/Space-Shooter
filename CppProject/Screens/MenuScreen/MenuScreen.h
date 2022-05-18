//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_MENUSCREEN_H
#define CPPPROJECT_MENUSCREEN_H

#include <raylib.h>
#include <list>
#include "../../GameObjects/BackgroundObject.h"
#include "../Screen.h"
#include "../../Utils/TextureEnum.h"
#include "../../Utils/TextureHolder.h"

class MenuScreen: public Screen {

public:
    MenuScreen(){
        backgroundObjects.push_back(
             new BackgroundObject(textureHolder->getTexture(TextureEnum::BACKGROUND))
                );

    }

    void Update() override {
        Screen::Update();
    };

    void Draw() override {
        Screen::Draw();

        DrawText(MENU_TITLE, (GetScreenWidth()-MeasureText(MENU_TITLE, 100))/2, GetScreenHeight()/6, 100, GOLD);
        DrawText(MOVE_INSTRUCTION, (GetScreenWidth()-MeasureText(MOVE_INSTRUCTION, 50))/2, GetScreenHeight()/6+200, 50, GOLD);
        DrawText(SHOT_INSTRUCTION, (GetScreenWidth()-MeasureText(SHOT_INSTRUCTION, 50))/2, GetScreenHeight()/6+300, 50, GOLD);
        DrawText(START_INSTRUCTION, (GetScreenWidth()-MeasureText(START_INSTRUCTION, 30))/2, GetScreenHeight()/6+450, 30, GOLD);
    };

private:
    const char* MENU_TITLE = "MENU";
    const char* MOVE_INSTRUCTION = "USE [W],[S],[A],[D] TO MOVE";
    const char* SHOT_INSTRUCTION = "SHOOT WITH [SPACE]";
    const char* START_INSTRUCTION = "PRESS [SPACE] TO START";

};


#endif //CPPPROJECT_MENUSCREEN_H
