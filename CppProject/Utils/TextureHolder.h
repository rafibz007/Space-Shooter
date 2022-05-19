//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_TEXTUREHOLDER_H
#define CPPPROJECT_TEXTUREHOLDER_H


#include <map>
#include <raylib.h>
#include "TextureEnum.h"

// SINGLETON
class TextureHolder {

protected:
    TextureHolder() = default;
    ~TextureHolder();
    static TextureHolder* textureHolder;

public:
    TextureHolder(TextureHolder&) = delete;
    void operator=(const TextureHolder&) = delete;
    void operator=(TextureHolder&&) = delete;

    static TextureHolder* GetInstance();

    Texture2D* getTexture(TextureEnum::ENUM);

private:
    std::map<TextureEnum::ENUM, Texture2D*> toTextureMap{};
};


#endif //CPPPROJECT_TEXTUREHOLDER_H
