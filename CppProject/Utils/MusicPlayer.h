//
// Created by rafibz007 on 19.05.22.
//

#ifndef CPPPROJECT_MUSICPLAYER_H
#define CPPPROJECT_MUSICPLAYER_H


#include <map>
#include <raylib.h>
#include "SoundEnum.h"
#include "MusicEnum.h"

class MusicPlayer {
protected:
    MusicPlayer() = default;
    ~MusicPlayer();
    static MusicPlayer* musicPlayer;

public:
    MusicPlayer(MusicPlayer&) = delete;
    void operator=(const MusicPlayer&) = delete;
    void operator=(MusicPlayer&&) = delete;

    static MusicPlayer* GetInstance();

    void playMusic(MusicEnum::ENUM);
    void playSound(SoundEnum::ENUM);

private:
    std::map<SoundEnum::ENUM, Sound*> toSoundMap{};
    std::map<MusicEnum::ENUM, Music*> toMusicMap{};
};


#endif //CPPPROJECT_MUSICPLAYER_H
