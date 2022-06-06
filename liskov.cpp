#include "liskov.h"
#include <iostream>
using namespace std;

void process(Rectangle &r)
{
    int w = r.get_width();
    r.set_height(10);
    cout<<"Expected:"<< w*10<<endl;
    cout<<"What we got:"<<r.area()<<endl;

}
int main(void)
{
    Square s{5};
    process(s);
}
