#include "entry.h"

#ifndef LOG_H
#define LOG_H

class Log
{
private:
    Entry log[512];
    int   counter;

public:
    Log();

    // Recording
    void addSuccess(Module module, Operation operation , bool success);

    // Print
    void printLog(int len);
};

#endif