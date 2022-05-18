//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_GAME_H
#define CPPPROJECT_GAME_H

#include <set>
#include "../Screen.h"
#include "../ScreenManager.h"
#include "../../GameObjects/Enemy/Enemy.h"
#include "../../GameObjects/Bullet/Bullet.h"
#include "../../GameObjects/Player/Player.h"

class Game: public Screen {
public:
    Game(): player{Player()}, enemies{}, bullets{}{
        backgroundObjects.push_back(
                new BackgroundObject(textureHolder->getTexture(TextureEnum::BACKGROUND))
                );
    }
    ~Game();

    void Update() override {
        Screen::Update();

        for (auto enemy : enemies)
            enemy->Update();

        for (auto bullet : bullets)
            bullet->Update();

        player.Update();
    };

    void Draw() override {
        Screen::Draw();

        for (auto enemy : enemies)
            enemy->Draw();

        for (auto bullet : bullets)
            bullet->Draw();

        player.Draw();
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
    std::set<Enemy*> enemies;
    std::set<Bullet*> bullets;
    Player player;
};


#endif //CPPPROJECT_GAME_H
