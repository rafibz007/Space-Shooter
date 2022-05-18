//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_ENDGAMESCREEN_H
#define CPPPROJECT_ENDGAMESCREEN_H


#include "../Screen.h"

class EndGameScreen: public Screen {

public:
    explicit EndGameScreen(int _score=0):score{_score}{
        backgroundObjects.push_back(
                new BackgroundObject(textureHolder->getTexture(TextureEnum::BACKGROUND))
                );
    }


    void Update() override {
        Screen::Update();
    };

    void Draw() override {
        Screen::Draw();

        const char* SCORE_MESSAGE = TextFormat("YOUR SCORE: %d", score);

        DrawText(END_GAME, (GetScreenWidth()-MeasureText(END_GAME, 100))/2, GetScreenHeight()/6, 100, GOLD);
        DrawText(SCORE_MESSAGE, (GetScreenWidth()-MeasureText(SCORE_MESSAGE, 50))/2, GetScreenHeight()/6+200, 50, GOLD);
        DrawText(START_INSTRUCTION, (GetScreenWidth()-MeasureText(START_INSTRUCTION, 30))/2, GetScreenHeight()/6+450, 30, GOLD);
    };


private:
    int score;
    const char* END_GAME = "GAME OVER";
    const char* START_INSTRUCTION = "PRESS [SPACE] TO START";
};


#endif //CPPPROJECT_ENDGAMESCREEN_H
