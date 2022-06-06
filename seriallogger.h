#ifndef SERIALLOGGER_H
#define SERIALLOGGER_H

#include "ilogger.h"
class SerialLogger: public ILogger
{
public:
    SerialLogger();
    void Log(const std::string &s) override;
};

#endif // SERIALLOGGER_H
