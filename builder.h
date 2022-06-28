/**
 * @author Javad Rahimi
 * @breif The Builder pattern is concerned with the creation of complicated objects,
        that is, objects that cannot be built up in a single-line constructor call.
 * @c MIT
 *
 */
#ifndef BUILDER_H
#define BUILDER_H
#include <string>
using namespace std;
 class HtmlElement
{
public:
    explicit HtmlElement() = delete;
    HtmlElement(string name, string value):name(name), value(value) {}

 private:
    string name;
    string value;
};

class Builder
{
public:
    Builder();
};

#endif // BUILDER_H
