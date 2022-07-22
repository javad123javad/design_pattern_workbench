#ifndef DECORATOR_H
#define DECORATOR_H

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Decorator
{
public:
    Decorator();
};

struct Shape
{
    virtual ~Shape();
    virtual string str() const = 0;

};

struct Circle: Shape
{
    Circle(const float radius):
        radius{radius}{}
    string str() const override;
private:
    float radius;

};

/**
 * @brief The ColoredShape struct. It is a composite
 * class which allows us to add various attribiutes to
 * another class without any direct inheritance.
 * This mechanism has several benefits:
 * 1. We respect the Single Responsibility Principle
 * 2. We respect the Open-Closed Principle. (i.e. Adding
 * features to the classes without modifying the original
 * types)
 * @note This is a Dynamic Decorator
 */
struct ColoredShape: Shape
{
    Shape & shape;
    string color;

    ColoredShape(Shape& shape,
                 const string& color):
        shape{shape},
        color{color}
    {

    }

    string str() const override;
};

template <typename T> struct TransparentShape: T
{
    static_assert (is_base_of<Shape, T>::value,
                   "Template argument must be a Shape");
    float trans_degree;

    string str() const override;


    TransparentShape(const float trans):
        T{0.1},
        trans_degree{trans}{}
};


#endif // DECORATOR_H
