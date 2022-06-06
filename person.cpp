#include "person.h"

Person::Person(int i_age)
{
    age = i_age;
}

int Person::getAge() const
{
    return age;
}

void Person::setAge(int value)
{
    age = value;
}
