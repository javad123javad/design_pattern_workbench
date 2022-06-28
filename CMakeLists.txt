cmake_minimum_required(VERSION 3.5)

project(DP_WB LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILE_FEATURES "-O2 -fno-exceptions -fno-rtti -Wall -Werror -pedantic-errors")

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
