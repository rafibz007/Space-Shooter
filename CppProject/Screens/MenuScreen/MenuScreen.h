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

    void Draw() override;

private:
    const char* MENU_TITLE = "MENU";
    const char* MOVE_INSTRUCTION = "USE [W],[S],[A],[D] TO MOVE";
    const char* SHOT_INSTRUCTION = "SHOOT WITH [SPACE]";
    const char* START_INSTRUCTION = "PRESS [ENTER] TO START";

};


#endif //CPPPROJECT_MENUSCREEN_H
