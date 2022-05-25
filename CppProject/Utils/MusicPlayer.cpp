//
// Created by rafibz007 on 19.05.22.
//

#include <iostream>
#include "MusicPlayer.h"

MusicPlayer* MusicPlayer::musicPlayer = nullptr;

MusicPlayer *MusicPlayer::GetInstance() {
    if (musicPlayer == nullptr)
        musicPlayer = new MusicPlayer();
    return musicPlayer;
}

MusicPlayer::~MusicPlayer() {
    for (auto sound : toSoundMap)
        UnloadSound(*sound.second);

    for (auto music : toMusicMap)
        UnloadMusicStream(*music.second);
}

void MusicPlayer::playMusic(MusicEnum::ENUM musicEnum) {
    auto* music = new Music();
    auto searchedMusic = toMusicMap.find(musicEnum);

    if (searchedMusic == toMusicMap.end()){
        *music = LoadMusicStream(MusicEnum::toString(musicEnum));
        SetMusicVolume(*music, MusicEnum::toVolume(musicEnum));
        toMusicMap.emplace(musicEnum, music);
    } else {
        music = searchedMusic->second;
    }

    stopMusic();
    currentMusicPlaying = music;
    PlayMusicStream(*music);
}

void MusicPlayer::playSound(SoundEnum::ENUM soundEnum) {
    auto* sound = new Sound();
    auto searchedSound = toSoundMap.find(soundEnum);

    if (searchedSound == toSoundMap.end()){
        *sound = LoadSound(SoundEnum::toString(soundEnum));
        SetSoundVolume(*sound, SoundEnum::toVolume(soundEnum));
        toSoundMap.emplace(soundEnum, sound);
    } else {
        sound = searchedSound->second;
    }

    PlaySoundMulti(*sound);
}

void MusicPlayer::stopMusic() {
    if (currentMusicPlaying == nullptr)
        return;

    StopMusicStream(*currentMusicPlaying);
    currentMusicPlaying = nullptr;
}

void MusicPlayer::Update() {
    if (currentMusicPlaying == nullptr)
        return;

    UpdateMusicStream(*currentMusicPlaying);
}

