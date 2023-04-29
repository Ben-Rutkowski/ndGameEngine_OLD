#define APPLICATION_MACROS
#include "application.h"

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
        startLoopFrame();
        pollInputs();
        endLoopFrame();
    }
}

// Log --------------------------------
void ndApp::printLog(int len) { log.printLog(len); }

// Private --------------------------------
void ndApp::startLoopFrame()              { event_manager.callStartFrameEvent(); }
void ndApp::endLoopFrame()                { event_manager.callEndFrameEvent(); }
void ndApp::pollInputs()
{
    window->pollInputs(event_manager);
    event_manager.callQueue();
}
void ndApp::distributeEvent(Event& event) 
{
    window->runEvent(event);
}

// Set callbacks
void ndApp::setEventCallback()
{
    CAST_VOID(ndApp::eventCallback, callback)
    event_manager.setEventCallback(callback);
}

// STATIC 
void ndApp::eventCallback(void* ptr, Event& event)
{
    CAST_APP(ptr, app)
    app->distributeEvent(event);
}