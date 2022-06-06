#ifndef ILOGGER_H
#define ILOGGER_H
#include <string>

using namespace std;

class ILogger
{
public:
    virtual ~ILogger() {}
    virtual void Log(const std::string &s) = 0;
};

#endif // ILOGGER_H
