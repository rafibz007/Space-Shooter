//
// Created by rafibz007 on 18.05.22.
//


#include "TextureEnum.h"

const char* TextureEnum::toString(ENUM anEnum){
    switch (anEnum) {
        case PLAYER_SHIP: return "../Textures/player_ship.png";
        case ENEMY_SHIP: return "";
        case BACKGROUND: return "../Textures/bg_sky.png";
        case BULLET: return "";
    }
    return "";
}

Vector2 TextureEnum::toSize(TextureEnum::ENUM anEnum) {
    switch (anEnum) {
        case PLAYER_SHIP: return Vector2{80, 60};
        default: return Vector2{-1,-1};
    }
}
