//
// Created by rafibz007 on 18.05.22.
//

#include "Game.h"
#include "../ScreenManager.h"

int Game::ENEMY_SCORE_VALUE = 100;

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

