//
// Created by rafibz007 on 18.05.22.
//

#include "ScreenManager.h"
ScreenManager* ScreenManager::screenManager = nullptr;

ScreenManager *ScreenManager::GetInstance() {
    if (screenManager == nullptr)
        screenManager = new ScreenManager();
    return screenManager;
}

void ScreenManager::showGame() {
    if (dynamic_cast<Game*>(currentScreen) != nullptr)
        return;
    delete currentScreen;
    currentScreenEnum = ScreenEnum::GAME;
    currentScreen = new Game();
}

void ScreenManager::showMenu() {
    if (dynamic_cast<MenuScreen*>(currentScreen) != nullptr)
        return;
    delete currentScreen;
    currentScreenEnum = ScreenEnum::MENU;
    currentScreen = new MenuScreen();
}

void ScreenManager::showEndGame(int finalScore) {
    if (dynamic_cast<EndGameScreen*>(currentScreen) != nullptr)
        return;
    delete currentScreen;
    currentScreenEnum = ScreenEnum::END;
    currentScreen = new EndGameScreen(finalScore);
}
