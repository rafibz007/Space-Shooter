//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_TEXTUREENUM_H
#define CPPPROJECT_TEXTUREENUM_H

#include <string>

class TextureEnum {
protected:


public:
    enum ENUM{
        PLAYER_SHIP,
        ENEMY_SHIP,
        BACKGROUND,
        BULLET,
    };

    static const char* toString(ENUM anEnum);
};


#endif //CPPPROJECT_TEXTUREENUM_H
