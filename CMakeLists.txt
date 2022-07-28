cmake_minimum_required(VERSION 3.5)

project(DP_WB LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILE_FEATURES "-O2 -fno-exceptions -fno-rtti -Wall -Werror -pedantic-errors")
#add_compile_definitions(_GLIBCXX_USE_CXX11_ABI=0)
find_package(Boost 1.70.0 COMPONENTS system filesystem serialization REQUIRED)

find_package(Microsoft.GSL CONFIG)

add_executable(DP_WB main.cpp
    person.cpp person.h
    filter.cpp filter.h
    specification.cpp specification.h
    personfilters.cpp   personfilters.h)
add_executable(Liskov_wb    liskov.cpp liskov.h)
#add_executable(Logger ilogger.cpp ilogger.h consolelogger.cpp consolelogger.h)

add_executable(Car
    car.cpp car.h
    engine.cpp engine.h
    engine_bmw.cpp engine_bmw.h
    consolelogger.cpp consolelogger.h
    seriallogger.cpp seriallogger.h
    ilogger.cpp ilogger.h
    di.hpp)
target_link_libraries(Car ${Boost_LIBRARIES})

add_executable(Creational creational.h creational.cpp)
add_executable(Builder builder.h builder.cpp)
add_executable(Composite-Builder composite_builder.h composite_builder.cpp)
add_executable(My-Composite-Builder my_composite_builder/my_composite_builder.h my_composite_builder/my_composite_builder.cpp
    my_composite_builder/personbuilderbase.h my_composite_builder/personbuilderbase.cpp
    my_composite_builder/person.h my_composite_builder/person.cpp)
add_executable(Factory factory.h factory.cpp)
add_executable(Prototype prototype.cpp prototype.h)
target_link_libraries(Prototype LINK_PUBLIC ${Boost_LIBRARIES})

add_executable(Singleton singleton.cpp singleton.h)
add_executable(Adaptor adaptor.cpp adaptor.h)
add_executable(PImpl pimpl.cpp pimpl.h)

add_executable(Composite Composite/composite.cpp Composite/composite.h)
add_executable(Decorator Decorator/decorator.cpp Decorator/decorator.h)
add_executable(Flyweight FlyWeight/flyweight.cpp FlyWeight/flyweight.h)
target_link_libraries(Flyweight LINK_PUBLIC ${Boost_LIBRARIES})
