//
// Created by rafibz007 on 19.05.22.
//

#ifndef CPPPROJECT_ENEMYSPAWNER_H
#define CPPPROJECT_ENEMYSPAWNER_H


#include <iostream>

class EnemySpawner {
public:
    EnemySpawner() = default;
    ~EnemySpawner() = default;

    void notifyEnemyDeath(){
        --enemiesAmount;
    }

    void Update();
    void spawnEnemy();


private:
    double timeSincePrevSpawn;
    int enemiesAmount;
    static int MAX_ENEMIES_AMOUNT;
    static float MIN_SPAWN_DELAY;
    static float MAX_SPAWN_DELAY;
    static float SPAWN_DELAY;
};


#endif //CPPPROJECT_ENEMYSPAWNER_H
