//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_GAMEOBJECT_H
#define CPPPROJECT_GAMEOBJECT_H


#include "Object.h"

class GameObject: public Object{
public:
    explicit GameObject(double _x=0, double _y=0, double _width=100, double _height=100, bool _collidable=true):
            Object(_x,_y,_width,_height), _isCollidable{_collidable}, _isDead{false}, _isDying{false}{}

    virtual bool hasCollision(const GameObject& gameObject);
    bool isDead() const{ return _isDead; }
    bool isCollidable() const{ return _isCollidable; }
    virtual void die(){
        _isCollidable = false;
        _isDead = true;
    }

protected:
    bool _isDying; //to allow waiting until dead animation is over before removing object
    bool _isCollidable; //to allow playing dead animation but not having collision
    bool _isDead;
};


#endif //CPPPROJECT_GAMEOBJECT_H
