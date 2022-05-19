//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_TEXTUREENUM_H
#define CPPPROJECT_TEXTUREENUM_H

#include <string>
#include <raylib.h>

class TextureEnum {
protected:


public:
    enum ENUM{
        PLAYER_SHIP,
        ENEMY_SHIP,
        BACKGROUND,
        PLAYER_BULLET,
        ENEMY_BULLET,
        EXPLOSION
    };

    static const char* toString(ENUM anEnum);
    static Vector2 toSize(ENUM anEnum);
};


#endif //CPPPROJECT_TEXTUREENUM_H
