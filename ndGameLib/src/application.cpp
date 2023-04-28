#define APPLICATION_MACROS
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

void ndApp::init() { setEventCallback(); }

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
void ndApp::distributeEvent(Event& event) 
{
    window->runEvent(event);
}

// Set callbacks
void ndApp::setEventCallback()
{
    GET_CALLBACK(ndApp::eventCallback, callback)
    event_manager.setEventCallback(callback);
}

// STATIC Callbacks 
void ndApp::eventCallback(void* ptr, Event& event)
{
    GET_APP(ptr, app)
    app->distributeEvent(event);
}