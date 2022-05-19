//
// Created by rafibz007 on 18.05.22.
//


#include "TextureEnum.h"

const char* TextureEnum::toString(ENUM anEnum){
    switch (anEnum) {
        case PLAYER_SHIP: return "../Textures/player_ship.png";
        case ENEMY_SHIP: return "../Textures/enemy_ship.png";
        case BACKGROUND: return "../Textures/bg_sky.png";
        case PLAYER_BULLET: return "../Textures/player_shot.png";
        case ENEMY_BULLET: return "../Textures/enemy_shot.png";
        case EXPLOSION: return "../Textures/boom_sprite_8_frames.png";
    }
    return "";
}

Vector2 TextureEnum::toSize(TextureEnum::ENUM anEnum) {
    switch (anEnum) {
        case PLAYER_SHIP: return Vector2{80, 60};
        case ENEMY_SHIP: return Vector2{65, 75};
        case PLAYER_BULLET: return Vector2{60, 15};
        case ENEMY_BULLET: return Vector2{60, 15};
        case EXPLOSION: return Vector2{8*120, 120};
        default: return Vector2{0,0};
    }
}
