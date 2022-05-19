//
// Created by rafibz007 on 19.05.22.
//

#include "SoundEnum.h"

const char *SoundEnum::toString(SoundEnum::ENUM anEnum) {
    switch (anEnum) {
        case PLAYER_HIT: return "../Sounds/boom2.wav";
        case ENEMY_HIT: return "../Sounds/boom3.wav";
        case GAME_START: return "../Sounds/game_start.wav";
        case GAME_OVER: return "../Sounds/game_over.mp3";
        case PLAYER_SHOOT: return "../Sounds/player_shoot.wav";
        case ENEMY_SHOOT: return "../Sounds/shoot3.wav";
        case PLAYER_EXPLOSION: return "../Sounds/player_boom.wav";
    }
    return "";
}

float SoundEnum::toVolume(SoundEnum::ENUM anEnum) {
    switch (anEnum) {
        case PLAYER_HIT: return 0.5;
        case PLAYER_SHOOT: return 0.5;
        case ENEMY_HIT: return 0.7;
        case ENEMY_SHOOT: return 0.5;
        case GAME_START: return 0.5;
        case GAME_OVER: return 0.35;
        case PLAYER_EXPLOSION: return 0.5;
    }
    return 0;
}
