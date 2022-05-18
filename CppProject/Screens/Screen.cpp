//
// Created by rafibz007 on 18.05.22.
//

#include "Screen.h"

void Screen::Draw() {
    for (auto bgObject: backgroundObjects) {
        bgObject->Draw();
    }
}

Screen::~Screen() {
    for (auto bgObject: backgroundObjects) {
        delete bgObject;
    }
}
