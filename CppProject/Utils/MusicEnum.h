//
// Created by rafibz007 on 19.05.22.
//

#ifndef CPPPROJECT_MUSICENUM_H
#define CPPPROJECT_MUSICENUM_H


class MusicEnum {
public:
    enum ENUM{
        MENU,
        GAME
    };

    static const char* toString(ENUM anEnum);
    static float toVolume(ENUM anEnum);
};


#endif //CPPPROJECT_MUSICENUM_H
