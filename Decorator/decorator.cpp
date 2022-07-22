#include "decorator.h"

Decorator::Decorator()
{

}
Shape::~Shape(){
}

string ColoredShape::str() const
{
    ostringstream oss;
    oss <<"A Colored Shape with"\
       "color:"<< this->color<<endl;
    return oss.str();
}

string Circle::str() const
{
    ostringstream oss;
    oss <<"A circle with radius:"\
       << this->radius<<endl;
    return oss.str();
}

template <typename T> string TransparentShape<T>::str() const
{
    ostringstream oss;
    oss << T::str() << "has trans degree:"
        << trans_degree;
        return oss.str();
}
int main(void)
{
    Circle circle{0.5f};
    ColoredShape cs{circle,"red"};
    TransparentShape<Circle> tshape{0.1f};
    cout<<cs.shape.str()<<std::endl;
    cout <<tshape.str()<<std::endl;


    return 0;
}
