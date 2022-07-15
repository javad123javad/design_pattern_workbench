#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <iostream>
#include <vector>

class Composite
{
public:
    Composite();
};

struct Object
{
    virtual void draw() = 0;
    virtual ~Object() = default;
};

struct Circle: Object
{
    void draw() override
    {
        std::cout<<"Drawing a Circle\n";
    }
//    virtual ~Circle() = default;
};

struct ObjectGroup: Object
{

    void draw() override
    {
        for(auto o: objs)
            o->draw();
    }

    void insert_object( Object * obj)
    {
        objs.push_back(obj);
    }
private:
    std::vector<Object*> objs;
};

#endif // COMPOSITE_H
