#include "entry.h"

#ifndef LOG_H
#define LOG_H

class Log
{
private:
    Entry  log[512];
    Module module;
    int    counter;

public:
    // Initialization
    Log(Module mod_in);

    // Recording
    void addSuccess(EntryOperation operation , bool success);

    // Print
    void printLog(int len);
};

#endif