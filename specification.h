#ifndef SPECIFICATION_H
#define SPECIFICATION_H
#include "person.h"
template<typename T>
struct Specification
{
    virtual bool is_statisfied(T* item) = 0;
};

struct AgeSpec: Specification<Person>
{
    bool is_statisfied(Person *item) override
    {
        if(item->getAge() > 10)
            return true;
        else
            return false;
    }

};
#endif // SPECIFICATION_H
