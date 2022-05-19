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

    void Draw() override;


private:
    int score;
    const char* END_GAME = "GAME OVER";
    const char* START_INSTRUCTION = "PRESS [ENTER] TO RETURN BACK TO MENU";
};


#endif //CPPPROJECT_ENDGAMESCREEN_H
