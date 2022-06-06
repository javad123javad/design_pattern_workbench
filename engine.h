#ifndef ENGINE_H
#define ENGINE_H

#include "ilogger.h"
#include <iostream>
#include <memory>
using namespace  std;
class Engine
{
public:
    Engine(    std::shared_ptr<ILogger> logger);

    friend ostream & operator<<(ostream& os, const Engine& obj)
    {
        return os<<"Volume:"<<obj.volume
                <<"horse_power: "<<obj.horse_power;
    }

    virtual void engine_type()
    {
        logger->Log("General Engine");

    }
protected:
    float volume{5};
    int horse_power{4};
    std::shared_ptr<ILogger> logger;

};

#endif // ENGINE_H
