//
// Created by rafibz007 on 18.05.22.
//

#include "Game.h"

void Game::startGame() {

}

void Game::stopGame() {
    ScreenManager::GetInstance()->showEndGame();
}

Game::~Game() {
    for (auto enemy : enemies)
        delete enemy;

    for (auto bullet : bullets)
        delete bullet;
}

