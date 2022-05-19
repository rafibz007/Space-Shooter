//
// Created by rafibz007 on 18.05.22.
//

#include "MenuScreen.h"

void MenuScreen::Draw() {
    Screen::Draw();

    DrawText(MENU_TITLE, (GetScreenWidth()-MeasureText(MENU_TITLE, 100))/2, GetScreenHeight()/6, 100, GOLD);
    DrawText(MOVE_INSTRUCTION, (GetScreenWidth()-MeasureText(MOVE_INSTRUCTION, 50))/2, GetScreenHeight()/6+200, 50, GOLD);
    DrawText(SHOT_INSTRUCTION, (GetScreenWidth()-MeasureText(SHOT_INSTRUCTION, 50))/2, GetScreenHeight()/6+300, 50, GOLD);
    DrawText(START_INSTRUCTION, (GetScreenWidth()-MeasureText(START_INSTRUCTION, 30))/2, GetScreenHeight()/6+450, 30, GOLD);

}
