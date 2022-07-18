#ifndef DECORATOR_H
#define DECORATOR_H

#include <string>
#include <iostream>
using namespace std;

class Decorator
{
public:
    Decorator();
};

struct Shape
{
    virtual ~Shape();
    virtual void str() const = 0;

};

struct Circle: Shape
{
    Circle(const float radius):
        radius{radius}{}
    void str() const override;
private:
    float radius;

};

/**
 * @brief The ColoredShape struct. It is a composite
 * class which allows us to add various attribiutes to
 * another class without any direct anheritance.
 * This mechanism has several benefits:
 * 1. We respect the Single Responsibility Principle
 * 2. We respect the Open-Closed Principle. (i.e. Adding
 * features to the classes without modifying the original
 * types)
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

    void str() const override;
};



#endif // DECORATOR_H
