#include <raylib.h>
#include "Screens/ScreenManager.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

int main()
{
//    INITIALIZATION
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "CapitanBombardiero");

    SetTargetFPS(60);

    ScreenManager* screenManager = ScreenManager::GetInstance();
    screenManager->showMenu();

//    MAIN GAME LOOP

    while (!WindowShouldClose())
    {
        // when game will end, Game class will switch game manager by itself
        if (screenManager->getScreenEnum() == ScreenManager::MENU && IsKeyDown(KEY_SPACE)){ // is in menu and press space to start game
            screenManager->showGame();
        } else if (screenManager->getScreenEnum() == ScreenManager::END && IsKeyDown(KEY_SPACE)) { // ended game and press space to go back to menu
            screenManager->showMenu();
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);
        screenManager->Draw();
        DrawFPS(10, 10);

        EndDrawing();
    }


//    CLEAN UP
    CloseWindow();

    return 0;
}