#include "decorator.h"

Decorator::Decorator()
{

}
Shape::~Shape(){
}

void ColoredShape::str() const
{
    cout<<"A Colored Shape with"\
       "color:"<< this->color<<endl;
}

void Circle::str() const
{
    cout<<"A circle with radius:"\
       << this->radius<<endl;
}

int main(void)
{
    Circle circle{0.5f};
    ColoredShape cs{circle,"red"};
    cs.shape.str();


    return 0;
}
