//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_SCREENMANAGER_H
#define CPPPROJECT_SCREENMANAGER_H


#include <iostream>
#include "Screen.h"
#include "MenuScreen/MenuScreen.h"
#include "Game/Game.h"
#include "EndGameScreen/EndGameScreen.h"

class ScreenManager: public Screen {
public:
    enum ScreenEnum{
        GAME,
        MENU,
        END
    };

protected:
    ScreenManager():currentScreen{nullptr}, currentScreenEnum{}, musicPlayer{MusicPlayer::GetInstance()} {}
    static ScreenManager* screenManager;

public:
    ScreenManager(ScreenManager&) = delete;
    void operator=(const ScreenManager&) = delete;
    void operator=(const ScreenManager&&) = delete;

    static ScreenManager* GetInstance();

    void Update() override{
        currentScreen->Update();
    }

    void Draw() override {
        currentScreen->Draw();
    }

    Game* getGame();

    void showGame();
    void showMenu();
    void showEndGame(int finalScore=0);

    ScreenEnum getScreenEnum(){
        return currentScreenEnum;
    }

private:
    Screen* currentScreen;
    ScreenEnum currentScreenEnum;
    MusicPlayer* musicPlayer;
};


#endif //CPPPROJECT_SCREENMANAGER_H
