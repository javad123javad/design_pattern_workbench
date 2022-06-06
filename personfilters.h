#ifndef PERSONFILTERS_H
#define PERSONFILTERS_H
#include "filter.h"
#include "person.h"
struct PersonFilters: Filter<Person>
{
    vector<Person *> filter(vector<Person*> items, Specification<Person> &spec) override
    {
        vector<Person*> result;

        for(auto person: items)
        {
            if(spec.is_statisfied(person))
                result.push_back(person);
        }

        return result;
    }
};

#endif // PERSONFILTERS_H
