#include "seriallogger.h"
#include <iostream>
SerialLogger::SerialLogger()
{

}

void SerialLogger::Log(const string &s)
{
    std::clog<<"[SERIAL LOG]: "<< s.c_str()<<endl;


}
