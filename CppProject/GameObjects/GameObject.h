//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_GAMEOBJECT_H
#define CPPPROJECT_GAMEOBJECT_H


#include "Object.h"

class GameObject: public Object{
public:
    explicit GameObject(double _x=0, double _y=0, double _width=100, double _height=100, bool _collidable=true):
        Object(_x,_y,_width,_height), collidable{_collidable}{}

protected:
    bool collidable; //to allow playing dead animation but not having collision
};


#endif //CPPPROJECT_GAMEOBJECT_H
