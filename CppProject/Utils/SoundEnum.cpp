//
// Created by rafibz007 on 19.05.22.
//

#include "SoundEnum.h"

const char *SoundEnum::toString(SoundEnum::ENUM anEnum) {
    switch (anEnum) {
        case PLAYER_HIT: return "";
        case ENEMY_HIT: return "";
        case GAME_START: return "";
        case GAME_OVER: return "../Sounds/game_over.mp3";
        case BACKGROUND_MUSIC: return "";
        case PLAYER_SHOOT: return "../Sounds/player_shoot.wav";
        case ENEMY_SHOOT: return "";
    }
    return "";
}

float SoundEnum::toVolume(SoundEnum::ENUM anEnum) {
    switch (anEnum) {
        case PLAYER_HIT: return 0.5;
        case PLAYER_SHOOT: return 0.5;
        case ENEMY_HIT: return 0.5;
        case ENEMY_SHOOT: return 0.5;
        case GAME_START: return 0.5;
        case GAME_OVER: return 0.5;
        case BACKGROUND_MUSIC: return 0.5;
    }
    return 0;
}
