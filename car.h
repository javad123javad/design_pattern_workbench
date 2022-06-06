#ifndef CAR_H
#define CAR_H
#include "engine.h"
#include "ilogger.h"
#include "consolelogger.h"
#include "seriallogger.h"
#include <memory>

class Car
{
public:
    Car( std::unique_ptr<Engine> engine,
         const std::shared_ptr<ILogger> & logger);
    friend std::ostream& operator<<(ostream& os, const Car& obj)
    {
        return os << "car with engine: "<< *obj.engine;
    }


private:
    std::unique_ptr<Engine> engine;
    std::shared_ptr<ILogger> logger;

};

#endif // CAR_H
