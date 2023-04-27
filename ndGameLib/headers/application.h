#include "log.h"
#include "window.h"
#include "event_manager.h"
#include "event.h"

#ifndef APPLICATION_H
#define APPLICATION_H

class ndApp
{
private:
    Log          log;
    ndWindow*    window;
    EventManager event_manager;

private:
    void pollInputs();
    void distributeEvent(Event& event);

    // Callbacks
    static void eventCallback(void* ptr, Event& event);

public:
    // Initialization
    ndApp();
    void init();
    void attachWindow(ndWindow* window_in);

    // Runtime
    void runApplication();
    
    // Log
    void printLog(int len) { log.printLog(len); }
};

#endif