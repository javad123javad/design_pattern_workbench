#include "composite_builder.h"
using namespace std;
Composite_Builder::Composite_Builder()
{

}


PersonBuilderBase::PersonBuilderBase(Person& person):
    person(person)
{

}
PersonBuilderBase::~PersonBuilderBase()
{
}
PersonAddressBuilder PersonBuilderBase::lives() const
{
    return *(new PersonAddressBuilder(person)) ;
}
PersonBuilder PersonBuilderBase::works() const
{
    return *(new PersonBuilder());
}
PersonBuilder Person::pp;
PersonBuilder Person::create()
{
    return pp;
}



int main()
{
    Person P = Person::create().lives().at("Hell").works().at("id");
    cout<<P.street_address<<endl;
}
