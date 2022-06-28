#ifndef FACTORY_H
#define FACTORY_H


class Factory
{
public:
    Factory();
};

struct Point
{
protected:
    Point(float x, float y): x{x}, y{y}{}
public:
    static Point PolarPoint(const float r, const float theta);
    static Point CartesianPoint(const float x, const float y);
private:
    float x;
    float y;
};


#endif // FACTORY_H
