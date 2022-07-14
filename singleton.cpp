#include "singleton.h"
#include <iostream>
Singleton &Singleton::get()
{
    static Singleton singleton;
    return singleton;
}

Singleton::Singleton()
{
    std::clog<<"I'm a Singleton!"<<std::endl;

}

int main()
{
//    Singleton::get();
    Printer prn1, prn2;
    prn1.set_id(12);

    fprintf(stderr,"Prn2 Id: %d\n", prn2.get_id());

}
