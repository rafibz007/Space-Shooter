//
// Created by rafibz007 on 18.05.22.
//

#ifndef CPPPROJECT_OBJECT_H
#define CPPPROJECT_OBJECT_H


class Object {
public:
    explicit Object(double _x=0, double _y=0, double _width=100, double _height=100):x{_x}, y{_y}, width{_width}, height{_height}{}
    ~Object() = default;

    virtual void Update() = 0;
    virtual void Draw() = 0;

protected:
    double x;
    double y;
    double width;
    double height;
};


#endif //CPPPROJECT_OBJECT_H
