#include "application.h"
#include <iostream>

// Constructor --------------------------------
ndApp::ndApp()
: log(APPLICATION), event_manager(this) {}

// Init --------------------------------
void ndApp::attachWindow(ndWindow* window_in) { window = window_in; }
void ndApp::init()
{
    // Set event callback
    void(*event_ptr)(void*, Event&) = ndApp::eventCallback;
    void* event_void = (void*)(event_ptr);
    event_manager.setEventCallback(event_void);
}

// Runloop --------------------------------
void ndApp::runApplication()
{
    log.addSuccess(START_RUN_LOOP, true);
    while (!window->getShouldClose())
    {
        pollInputs();
        window->setShouldClose(true);
    }
}

void ndApp::pollInputs() { window->pollInputs(event_manager); }

// Log --------------------------------
void ndApp::printLog(int len) { log.printLog(len); }

// Events --------------------------------
void ndApp::distributeEvent(Event& event)
{
    window->runEvent(event);
}

// Callbacks --------------------------------
void ndApp::eventCallback(void* ptr, Event& event)
{
    ndApp* app_ptr = static_cast<ndApp*>(ptr);
    app_ptr->distributeEvent(event);
}