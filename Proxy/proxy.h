#ifndef PROXY_H
#define PROXY_H

#include <ostream>

class Proxy
{
public:
    Proxy();
};

template<typename T>
class Property
{
public:
    Property(T value)
        : value{value}
    {

    }

    T operator=(const T value)
    {
        this->value = value;
    }
     operator T()
    {
        return value;
    }

protected:
    T value;
};
/////////// Virtual Proxy

#endif // PROXY_H


