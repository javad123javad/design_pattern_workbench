#include <iostream>
#include "person.h"
#include "personfilters.h"
#include "specification.h"
using namespace std;

int main()
{
    vector<Person*> persons;
    PersonFilters ft1;
    AgeSpec sp1;
    for(int i = 0; i < 20; i++)
    {
        persons.push_back(new Person(i));
    }
    vector<Person*> res = ft1.filter(persons, sp1);
    for(auto per: res)
        cout << "Hello:" <<per->getAge()<< endl;
    return 0;
}
