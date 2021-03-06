//
// Created by rafibz007 on 19.05.22.
//

#include "MusicEnum.h"

const char *MusicEnum::toString(MusicEnum::ENUM anEnum) {
    switch (anEnum) {
        case MENU: return "../Music/menu.mp3";
        case GAME: return "../Music/game.mp3";
    }
    return "";
}

float MusicEnum::toVolume(MusicEnum::ENUM anEnum) {
    switch (anEnum) {
        case MENU: return 0.3;
        case GAME: return 0.15;
    }
    return 0;
}
