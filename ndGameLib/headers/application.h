#include "log.h"
#include "window.h"

#ifndef APPLICATION_H
#define APPLICATION_H

class ndApp
{
private:
    Log       log;
    ndWindow* window;

public:
    ndApp();

    // Init
    void attachWindow(ndWindow* window_in);

    // Runloop
    void runApplication();

    // Log
    void displayLog(int len);
};

#endif