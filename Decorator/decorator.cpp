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
void printer()
{
    cout<<"I'm a printer"<<endl;
}

int add(int a, int b)
{
    cout<<"Doing calculation"<<endl;

    return a+b;
}
int main(void)
{
//    Circle circle{0.5f};
//    ColoredShape cs{circle,"red"};
//    TransparentShape<Circle> tshape{0.1f};
//    cout<<cs.shape.str()<<std::endl;
//    cout <<tshape.str()<<std::endl;
    Logger c(printer, "Hello Function");

    c();
    auto call = make_logger2(
                []()
    {
        cout<<"Hello 2"<<endl;
    }, "Hello2 Function");
    call();

//    auto call2 = make_logger3(add,"Add");
//    auto result = call2(2,5);
    auto caller = Logger3<int(int,int)>(add, "test");
       auto res = caller(3, 4);
       std::cout << "result: " << res << std::endl;
       return 0;
    return 0;
}
