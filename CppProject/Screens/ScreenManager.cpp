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
    musicPlayer->playMusic(MusicEnum::GAME);
    musicPlayer->playSound(SoundEnum::GAME_START);
}

void ScreenManager::showMenu() {
    if (dynamic_cast<MenuScreen*>(currentScreen) != nullptr)
        return;
    delete currentScreen;
    currentScreenEnum = ScreenEnum::MENU;
    currentScreen = new MenuScreen();
    musicPlayer->playMusic(MusicEnum::MENU);
}

void ScreenManager::showEndGame(int finalScore) {
    if (dynamic_cast<EndGameScreen*>(currentScreen) != nullptr)
        return;
    delete currentScreen;
    currentScreenEnum = ScreenEnum::END;
    currentScreen = new EndGameScreen(finalScore);
    musicPlayer->playSound(SoundEnum::GAME_OVER);
    musicPlayer->stopMusic();
}

Game *ScreenManager::getGame() {
    if (currentScreenEnum == ScreenEnum::GAME)
        return (Game*)currentScreen;
    return nullptr;
}
