//
// Created by rafibz007 on 18.05.22.
//

#include "Game.h"
#include "../ScreenManager.h"

int Game::ENEMY_SCORE_VALUE = 100;

void Game::startGame() {

}

void Game::stopGame() {
    ScreenManager::GetInstance()->showEndGame(score);
}

Game::~Game() {
    for (auto enemy : enemies)
        delete enemy;

    for (auto bullet : bullets)
        delete bullet;
}

void Game::Draw() {
    Screen::Draw();

    for (auto enemy : enemies)
        enemy->Draw();

    player.Draw();

    for (auto bullet : bullets)
        bullet->Draw();

    DrawText(TextFormat("Lives: %d", player.getLives()), 10,10,50,GOLD);
    DrawText(TextFormat("Score: %d", score), GetScreenWidth()-10-MeasureText(TextFormat("Score: %d", score), 50),10,50,GOLD);

}

void Game::Update() {
    Screen::Update();

//        BULLETS
    for (auto bullet : bullets){
        bullet->Update();
        if (bullet->isOut())
            markedToDeleteBullets.insert(bullet);

//            check if enemy bullet hit the player
//            and check if player bullet collides with enemy
        if (bullet->isPlayerBullet()){
            for (auto enemy: enemies) {
                if (bullet->hasCollision(*enemy)){
                    enemy->die();
                    bullet->die();
                    score += ENEMY_SCORE_VALUE;
                }
            }
        } else {
            if (bullet->hasCollision(player)){
                bullet->die();
                player.receiveDamage();
            }
        }

        if (bullet->isDead())
            markedToDeleteBullets.insert(bullet);
    }

    for (auto markedBullet : markedToDeleteBullets) {
        bullets.erase(markedBullet);
        delete markedBullet;
    }
    markedToDeleteBullets.clear();


//        ENEMIES
    for (auto enemy : enemies) {
        enemy->Update();
        if (enemy->isOut() || enemy->isDead())
            markedToDeleteEnemies.insert(enemy);
        else if (enemy->hasCollision(player)){
            player.receiveDamage();
            enemy->die();
        }
    }

    for (auto marketEnemy : markedToDeleteEnemies) {
        enemies.erase(marketEnemy);
        delete marketEnemy;
    }
    markedToDeleteEnemies.clear();


//        PLAYER
    player.Update();
    if (!player.hasLives() && player.isCollidable())
        player.die();

    if (player.isDead())
        stopGame();

//        SPAWNER
    enemySpawner.Update();
}

