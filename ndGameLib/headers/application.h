#include "log.h"

#ifndef APPLICATION_H
#define APPLICATION_H

class ndApp
{
private:
    Log log;

public:
    ndApp() {}

    // Runloop
    void runApplication();

    // Log
    void displayLog(int len);
};

#endif