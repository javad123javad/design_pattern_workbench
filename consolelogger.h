#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "ilogger.h"

class ConsoleLogger: public ILogger
{
public:
    ConsoleLogger();
    void Log(const std::string &s) override;
};

#endif // CONSOLELOGGER_H
