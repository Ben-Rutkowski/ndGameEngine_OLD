#include "event_manager.h"
#include <iostream>

// Initialization --------------------------------
EventManager::EventManager(void* ptr) : app_ptr{ ptr } {}

void EventManager::setEventCallback(void* ptr)
{
    evt_call callback = (evt_call)ptr;
    event_callback = callback;
}

// Event --------------------------------
void EventManager::callKeyEvent(Key key)
{
    KeyEvent event(key);
    callEvent(event);
}

void EventManager::callResize(int width, int height)
{
    // TODO: create resize event
}
