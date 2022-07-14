/***
 * @brief: Impl pattern helps up to hide the implementation of
 * the mothod of a class. In this case we need ab implementor
 * class which implements the class body and then returns a
 * pointer
 * ***/
#ifndef PIMPL_H
#define PIMPL_H

#include <string>

class Person
{

    std::string name;
    class ImplPerson;
    ImplPerson *impl;

public:

    Person(std::string name);
    ~Person();
    void greet();


};

#endif // PIMPL_H
