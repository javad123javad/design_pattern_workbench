#include "pimpl.h"


#include <iostream>

class Person::ImplPerson
{
public:
    void greet(Person * p)
    {
        std::cout<<"Hello "<<p->name<<std::endl;

    }

};
Person::Person(std::string name):
    name{name}    ,
    impl{new ImplPerson}
{

}
Person::~Person(){
    delete impl;
}

void Person::greet()
{
    impl->greet(this);
}
int main()
{
    Person j("Javad");
    j.greet();
    return 0;
}
