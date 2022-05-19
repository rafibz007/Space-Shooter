#include <raylib.h>
#include "Screens/ScreenManager.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

int main()
{
//    INITIALIZATION
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "CapitanBombardiero");
    InitAudioDevice();
    SetMasterVolume(100);

    SetTargetFPS(60);

    ScreenManager* screenManager = ScreenManager::GetInstance();
    screenManager->showMenu();

//    MAIN GAME LOOP
    while (!WindowShouldClose())
    {
//        CHANGE STATE
        // when game will end, Game class will switch game manager by itself
        if (screenManager->getScreenEnum() == ScreenManager::MENU && IsKeyReleased(KEY_ENTER)){ // is in menu and press enter to start game
            screenManager->showGame();
        } else if (screenManager->getScreenEnum() == ScreenManager::END && IsKeyReleased(KEY_ENTER)) { // ended game and press enter to go back to menu
            screenManager->showMenu();
        }

//        UPDATE
        screenManager->Update();

//        DRAW
        BeginDrawing();

        ClearBackground(RAYWHITE);
        screenManager->Draw();
        DrawFPS(10, 10);

        EndDrawing();
    }


//    CLEAN UP
    StopSoundMulti();

    CloseAudioDevice();
    CloseWindow();

    return 0;
}