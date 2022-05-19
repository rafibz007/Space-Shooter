//
// Created by rafibz007 on 18.05.22.
//

#include "TextureHolder.h"
TextureHolder* TextureHolder::textureHolder = nullptr;

TextureHolder *TextureHolder::GetInstance() {
    if (textureHolder == nullptr){
        textureHolder = new TextureHolder();
    }
    return textureHolder;
}


Texture2D* TextureHolder::getTexture(TextureEnum::ENUM textureEnum) {
    auto* texture = new Texture2D();
    auto searchedTexture = toTextureMap.find(textureEnum);
    if (searchedTexture == toTextureMap.end()){
        Image image = LoadImage(TextureEnum::toString(textureEnum)); // Load image in CPU memory (RAM)

        Vector2 size = TextureEnum::toSize(textureEnum);
        if (size.x > 0 && size.y > 0) {
            ImageResize(&image, size.x, size.y);
        }

        *texture = LoadTextureFromImage(image);  // Image converted to textureEnum, uploaded to GPU memory (VRAM)
        UnloadImage(image);

        toTextureMap.emplace(textureEnum, texture);
        return texture;
    } else {
        texture = searchedTexture->second;
    }
    return texture;
}

TextureHolder::~TextureHolder() {
    for (auto texture : toTextureMap) {
        UnloadTexture(*texture.second);
    }
}

