//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_GAME_H
#define CPPPROJECT_GAME_H

#include <set>
#include <unordered_set>
#include "../Screen.h"
#include "../../GameObjects/Enemy/Enemy.h"
#include "../../GameObjects/Bullet/Bullet.h"
#include "../../GameObjects/Player/Player.h"
#include "../../GameObjects/Enemy/EnemySpawner.h"

class Game: public Screen {
public:
    Game(): player{Player()}, enemies{}, bullets{}, enemySpawner{EnemySpawner()}{
        backgroundObjects.push_back(
                new BackgroundObject(textureHolder->getTexture(TextureEnum::BACKGROUND))
                );
    }
    ~Game();

    void Update() override {
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
                    if (bullet->hasCollision(*enemy) && enemy->isCollidable()){
                        enemy->die();
                        bullet->die();
                        score += ENEMY_SCORE_VALUE;
                    }
                }
            } else {
                if (bullet->hasCollision(player) && player.isCollidable()){
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
        }

        for (auto marketEnemy : markedToDeleteEnemies) {
            enemySpawner.notifyEnemyDeath();
            enemies.erase(marketEnemy);
            delete marketEnemy;
        }
        markedToDeleteEnemies.clear();


//        PLAYER
        player.Update();
        if (!player.hasLives())
            player.die();

        if (player.isDead())
            stopGame();

//        SPAWNER
        enemySpawner.Update();
    };

    void Draw() override {
        Screen::Draw();

        for (auto enemy : enemies)
            enemy->Draw();

        player.Draw();

        for (auto bullet : bullets)
            bullet->Draw();

        DrawText(TextFormat("Lives: %d", player.getLives()), 10,10,50,GOLD);
        DrawText(TextFormat("Score: %d", score), GetScreenWidth()-10-MeasureText(TextFormat("Score: %d", score), 50),10,50,GOLD);
    };

    void addBullet(Bullet* bullet){
        bullets.insert(bullet);
    }

    void addEnemy(Enemy* enemy){
        enemies.insert(enemy);
    }

    void startGame();
    void stopGame();

private:
    std::unordered_set<Enemy*> enemies;
    std::unordered_set<Enemy*> markedToDeleteEnemies{};
    std::unordered_set<Bullet*> bullets;
    std::unordered_set<Bullet*> markedToDeleteBullets{};
    EnemySpawner enemySpawner;
    Player player;
    int score{0};
    static int ENEMY_SCORE_VALUE;
};


#endif //CPPPROJECT_GAME_H
