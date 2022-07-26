#ifndef DECORATOR_H
#define DECORATOR_H

#include <string>
#include <iostream>
#include <sstream>
#include <functional>
using namespace std;

class Decorator
{
public:
    Decorator();
};

struct Shape
{
    virtual ~Shape();
    virtual string str() const = 0;

};

struct Circle: Shape
{
    Circle(const float radius):
        radius{radius}{}
    string str() const override;
private:
    float radius;

};

/**
 * @brief The ColoredShape struct. It is a composite
 * class which allows us to add various attribiutes to
 * another class without any direct inheritance.
 * This mechanism has several benefits:
 * 1. We respect the Single Responsibility Principle
 * 2. We respect the Open-Closed Principle. (i.e. Adding
 * features to the classes without modifying the original
 * types)
 * @note This is a Dynamic Decorator
 */
struct ColoredShape: Shape
{
    Shape & shape;
    string color;

    ColoredShape(Shape& shape,
                 const string& color):
        shape{shape},
        color{color}
    {

    }

    string str() const override;
};

template <typename T> struct TransparentShape: T
{
    static_assert (is_base_of<Shape, T>::value,
                   "Template argument must be a Shape");
    float trans_degree;

    string str() const override;


    TransparentShape(const float trans):
        T{0.1},
        trans_degree{trans}{}
};

struct Logger
{
    std::function<void()> func;
    string name;

    Logger(const function<void()>& func,
           const string& name):
        func{func},
        name{name}
    {

    }

    void operator()() const
    {
        cout<< "Entering "<<name<<endl;
        func();
        cout<<"Exiting "<<name<<endl;
    }
    void operator()(int i)const
    {
        cout<<"Works: "<<i<<endl;
    }

};

template <typename Func>
struct Logger2
{
    Func func;
    string name;

    Logger2(const Func& func,
            const string& name):
        func{func},
        name{name}
    {

    }
    void operator()() const
    {
        cout<< "Entering "<<name<<endl;
        func();
        cout<<"Exiting "<<name<<endl;
    }
};

template <typename Func>
auto make_logger2(
        Func func,
        const string& name)
{
    return Logger2<Func>{func, name};
};

template <typename F>
class Logger3;
template <typename R, typename... Args>
class Logger3<R(Args...)>
{
    public:
    Logger3(function<R(Args...)> func,
            const string& name):
        func{func},
        name{name}
    {}
    R operator() (Args ...args)
    {
        cout << "Entering " << name << endl;
        R result = func(std::forward<Args>(args)...);
        std::cout << "Exiting " << name << std::endl;
        return result;
    }
    private:
    function<R(Args...)> func;
    string name;
};
template <typename R, typename... Args>
class Logger4
{
public:
    Logger4(std::function<R(Args...)> func,
        const std::string& name) :
        func{ func },
        name{ name }
    {}
    R operator() (Args ...args)
    {
        std::cout << "Entering " << name << std::endl;
        R result = func(std::forward<Args>(args)...);
        std::cout << "Exiting " << name << std::endl;
        return result;
    }
private:
    std::function<R(Args...)> func;
    std::string name;
};

template <typename R, typename... Args>
auto make_logger3(R (*func)(Args...),
                  const string& name)
{
    return Logger3<R(Args...)>(
                std::function<R(Args...)>(func),
                name);
}
#endif // DECORATOR_H
