//
// Created by rafibz007 on 18.05.22.
//

#include "EndGameScreen.h"


void EndGameScreen::Draw() {
    Screen::Draw();

    const char* SCORE_MESSAGE = TextFormat("YOUR SCORE: %d", score);

    DrawText(END_GAME, (GetScreenWidth()-MeasureText(END_GAME, 100))/2, GetScreenHeight()/6, 100, GOLD);
    DrawText(SCORE_MESSAGE, (GetScreenWidth()-MeasureText(SCORE_MESSAGE, 50))/2, GetScreenHeight()/6+200, 50, GOLD);
    DrawText(START_INSTRUCTION, (GetScreenWidth()-MeasureText(START_INSTRUCTION, 30))/2, GetScreenHeight()/6+450, 30, GOLD);

}
