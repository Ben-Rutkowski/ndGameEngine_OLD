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
    // Initialization
    ndApp();
    void init();
    void attachWindow(ndWindow* window_in);

    // Runtime
    void runApplication();
    
    // Log
    void printLog(int len);

private:
    void pollInputs();
    void startLoopFrame();
    void endLoopFrame();
    void distributeEvent(Event& event);

    // Callbacks
    void setEventCallback();
    static void eventCallback(void* ptr, Event& event);
};

#endif

#ifdef APPLICATION_MACROS

#define GET_CALLBACK(FUNCTION, CALLBACK) \
    void(*event_ptr)(void*, Event&) = FUNCTION; \
    void* CALLBACK = (void*)(event_ptr); \

#define GET_APP(PTR, APP) ndApp* APP = static_cast<ndApp*>(PTR);

#endif