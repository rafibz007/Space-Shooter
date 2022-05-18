//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_BACKGROUNDOBJECT_H
#define CPPPROJECT_BACKGROUNDOBJECT_H


#include <raylib.h>
#include <memory>
#include <utility>
#include "Object.h"

class BackgroundObject: public Object {

public:
    explicit BackgroundObject(Texture2D* texture2D):
        Object(
                (double )(GetScreenWidth()/2 - GetScreenWidth()/2),
                (double )(GetScreenHeight()/2 - GetScreenHeight()/2),
                GetScreenWidth(),
                GetScreenHeight()
                ),
        texture{texture2D}{}

    void Update() override{};

    void Draw() override {
        DrawTexture(*texture, x, y, WHITE);
    };

private:
    Texture2D* texture;
};


#endif //CPPPROJECT_BACKGROUNDOBJECT_H
