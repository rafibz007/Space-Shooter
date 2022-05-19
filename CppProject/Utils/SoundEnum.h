//
// Created by rafibz007 on 19.05.22.
//

#ifndef CPPPROJECT_SOUNDENUM_H
#define CPPPROJECT_SOUNDENUM_H


class SoundEnum {
public:
    enum ENUM{
        PLAYER_HIT,
        PLAYER_SHOOT,
        ENEMY_HIT,
        ENEMY_SHOOT,
        GAME_START,
        GAME_OVER,
        BACKGROUND_MUSIC
    };

    static const char* toString(ENUM anEnum);
    static float toVolume(ENUM anEnum);
};


#endif //CPPPROJECT_SOUNDENUM_H
