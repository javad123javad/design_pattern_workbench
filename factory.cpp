#include "factory.h"
#include <math.h>
Factory::Factory()
{

}

Point Point::PolarPoint(const float r, const float theta)
{
    return {r*cos(theta), r*(sin(theta))};
}

Point Point::CartesianPoint(const float x, const float y)
{
    return {x, y};
}

int main()
{
    Point polar = Point::PolarPoint(10, M_PI_4);

}
