#ifndef FILTER_H
#define FILTER_H
#include "specification.h"
#include <vector>
using namespace std;

template<typename T>
struct Filter
{
    virtual vector<T*> filter(vector<T*> items, Specification<T> &spec)=0;

};

#endif // FILTER_H
