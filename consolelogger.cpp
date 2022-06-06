#include "consolelogger.h"
#include <iostream>

ConsoleLogger::ConsoleLogger()
{

}

void ConsoleLogger::Log(const string &s)
{
    std::clog<<"LOG: "<< s.c_str()<<std::endl;

}

