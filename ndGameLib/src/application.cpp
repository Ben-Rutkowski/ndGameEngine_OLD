#include "application.h"
#include <iostream>

// Initialization --------------------------------
ndApp::ndApp()
: log(Module::APPLICATION), event_manager(this) {}

void ndApp::attachWindow(ndWindow* window_in)
{
    window = window_in;
    window->setEventManager(&event_manager);
    window->setCallbacks();
}

void ndApp::init()
{
    setEventCallback();
}

// Runtime --------------------------------
void ndApp::runApplication()
{
    log.addSuccess(EntryOperation::START_RUN_LOOP, true);
    while (!window->getShouldClose())
    {
        pollInputs();
        endLoopFrame();
    }
}

// Log --------------------------------
void ndApp::printLog(int len) { log.printLog(len); }

// Private --------------------------------
void ndApp::pollInputs()                  { window->pollInputs(event_manager); }
void ndApp::startLoopFrame()              {}
void ndApp::endLoopFrame()                { window->endLoopFrame(); }
void ndApp::distributeEvent(Event& event) { window->runEvent(event); }

// Set callbacks
void ndApp::setEventCallback()
{
    void(*event_ptr)(void*, Event&) = ndApp::eventCallback;
    void* event_void = (void*)(event_ptr);
    event_manager.setEventCallback(event_void);
}

// STATIC Callbacks 
void ndApp::eventCallback(void* ptr, Event& event)
{
    ndApp* app_ptr = static_cast<ndApp*>(ptr);
    app_ptr->distributeEvent(event);
}