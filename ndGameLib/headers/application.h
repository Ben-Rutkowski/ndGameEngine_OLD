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

public:
    ndApp();

    // Init
    void attachWindow(ndWindow* window_in);
    void init();

    // Runloop
    void runApplication();
    void pollInputs();

    // Log
    void printLog(int len);

    // Events
    void distributeEvent(Event& event);

    // Callbacks
    static void eventCallback(void* ptr, Event& event);
};

#endif