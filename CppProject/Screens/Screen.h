//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_SCREEN_H
#define CPPPROJECT_SCREEN_H


#include <list>
#include "../Utils/TextureHolder.h"
#include "../GameObjects/BackgroundObject.h"

class Screen {

public:
    Screen(): backgroundObjects{}, textureHolder{TextureHolder::GetInstance()}{}
    ~Screen();

    virtual void Update(){};
    virtual void Draw();

protected:
    std::list<BackgroundObject*> backgroundObjects{};
    TextureHolder* textureHolder;
};


#endif //CPPPROJECT_SCREEN_H
