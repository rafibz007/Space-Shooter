//
// Created by rafibz007 on 18.05.22.
//


#include "TextureEnum.h"

const char* TextureEnum::toString(ENUM anEnum){
    switch (anEnum) {
        case PLAYER_SHIP: return "";
        case ENEMY_SHIP: return "";
        case BACKGROUND: return "../Textures/bg_sky.png";
        case BULLET: return "";
    }
    return "";
}