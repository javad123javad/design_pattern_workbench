#include "flyweight.h"

FlyWeight::FlyWeight()
{

}

int main(void)
{

    User u("Javad", "Rahimi");
    User u2("Javad","Ebrahimi");
    std::cout<<u<<std::endl;
    std::cout<<u2<<std::endl;

    return 0;
}
