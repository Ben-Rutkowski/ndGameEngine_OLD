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
void EventManager::callCloseEvent()
{
    Event event(EventType::CLOSE);
    callEvent(event);

}
void EventManager::callResizeEvent(int width, int height)
{ 
    ResizeEvent event(width, height);
    callEvent(event);
}

// Private --------------------------------
void EventManager::callEvent(Event& event) { event_callback(app_ptr, event); }