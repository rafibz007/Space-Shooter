//
// Created by rafibz007 on 19.05.22.
//

#include <raylib.h>
#include <random>
#include "EnemySpawner.h"
#include "Enemy.h"
#include "Logics/ForwardLogic.h"
#include "../../Screens/ScreenManager.h"

int EnemySpawner::MAX_ENEMIES_AMOUNT = 20;
float EnemySpawner::SPAWN_DELAY = 1;
float EnemySpawner::MAX_SPAWN_DELAY = 2;
float EnemySpawner::MIN_SPAWN_DELAY = 0.5;

void EnemySpawner::Update() {
    timeSincePrevSpawn += GetFrameTime();
    if (timeSincePrevSpawn >= SPAWN_DELAY && enemiesAmount < MAX_ENEMIES_AMOUNT){
        spawnEnemy();
    }
}

void EnemySpawner::spawnEnemy() {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(10, GetScreenHeight()-10-Enemy::HITBOX_HEIGHT); // define the range

    auto* enemy = new Enemy(GetScreenWidth(), distr(gen), ForwardLogic());
    auto* game = ScreenManager::GetInstance()->getGame();
    if (game != nullptr){
        game->addEnemy(enemy);
        enemiesAmount++;
        timeSincePrevSpawn = 0;
    }
}
