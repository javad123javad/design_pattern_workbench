#ifndef COMPOSITE_BUILDER_H
#define COMPOSITE_BUILDER_H

#include <iostream>

class Composite_Builder
{
public:
    Composite_Builder();
};

////////////////////////
/// \brief The Person class
///

class PersonAddressBuilder;
class PersonBuilder;
class Person
{
public:
    Person(){};
    ~Person(){};
    static PersonBuilder pp;
    static PersonBuilder create();//{return pp;};
    std::string street_address, post_code, city, home_address;
    std::string company_name, position;
    int annual_income = 0;
};
class PersonBuilderBase
{
protected:
    Person & person;

public:

    explicit PersonBuilderBase(Person& person);
    ~PersonBuilderBase();
public:
    operator Person()
    {
        return std::move(person);
    }
    PersonAddressBuilder    lives() const;
    PersonBuilder           works() const;
};

class PersonBuilder: public PersonBuilderBase
{
    Person p;
    typedef PersonBuilder self;
public:
    PersonBuilder(): PersonBuilderBase{p}{}
    self& at(std::string home_address)
    {
        person.home_address = home_address;
        std::cout<<"I Live in:"<<home_address<<std::endl;
        return *this;
    }
};

class PersonAddressBuilder: public PersonBuilderBase
{
    typedef PersonAddressBuilder self;
public:
    explicit PersonAddressBuilder(Person& person): PersonBuilderBase(person){};

    self& at(std::string street_address)
    {
        std::cout<<"Im work in:"<< street_address<<std::endl;
        person.street_address = street_address;
        return *this;
    }

};


#endif // COMPOSITE_BUILDER_H
