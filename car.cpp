#include "car.h"
#include "di.hpp"

namespace di = boost::di;

Car::Car(std::unique_ptr<Engine> engine,
         const std::shared_ptr<ILogger> & logger):
    engine{std::move(engine)},
    logger{logger}

{
    logger->Log("Makeing a car");

}

int  main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    auto injector = di::make_injector(
                di::bind<ILogger>().to<ConsoleLogger>());
    auto serial_injector = di::make_injector(
                di::bind<ILogger>().to<SerialLogger>());

    auto carA = injector.create<Car>();
    auto carB = serial_injector.create<Car>();
    std::cout<<carA<<endl;
//    auto app_ = di::make_injector().create<Car>();
    return 0;
}
