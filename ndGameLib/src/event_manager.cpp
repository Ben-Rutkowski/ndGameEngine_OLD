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
    KeyEvent key_event(key);
    callEvent(key_event);
}

void EventManager::callResize(int width, int height)
{
    // TODO: create resize event
}

// Private --------------------------------
void EventManager::callEvent(Event& event) { event_callback(app_ptr, event); }