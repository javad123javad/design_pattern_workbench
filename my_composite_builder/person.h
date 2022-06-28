#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;;
class PersonBuilder;

class Person
{
    string pname;
public:
    Person(string name);
    static PersonBuilder create();

};

class PersonBuilder{


    explicit PersonBuilder(){}
    Person*    build_person(string name)
    {
        return new Person(name);
    }

};

#endif // PERSON_H
