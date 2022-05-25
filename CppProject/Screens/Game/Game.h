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
    Game(): player{Player()}, enemySpawner{EnemySpawner()}, score{0}{
        backgroundObjects.push_back(
                new BackgroundObject(textureHolder->getTexture(TextureEnum::BACKGROUND))
                );
    }
    ~Game();

    void Update() override;

    void Draw() override;

    void addBullet(Bullet* bullet){
        bullets.insert(bullet);
    }

    void addEnemy(Enemy* enemy){
        enemies.insert(enemy);
    }

    void startGame();
    void stopGame();

    int getScore() const{
        return score;
    }

private:
    static int ENEMY_SCORE_VALUE;

    std::unordered_set<Enemy*> enemies{};
    std::unordered_set<Enemy*> markedToDeleteEnemies{};
    std::unordered_set<Bullet*> bullets{};
    std::unordered_set<Bullet*> markedToDeleteBullets{};
    EnemySpawner enemySpawner;
    Player player;
    int score;

};


#endif //CPPPROJECT_GAME_H
