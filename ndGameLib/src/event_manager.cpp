#include "event_manager.h"

// Sets --------------------------------
void EventManager::setEventCallback(void* ptr)
{
    evt_call callback = (evt_call)ptr;
    event_callback = callback;
}

// Event --------------------------------
void EventManager::callEvent(Event& event) { event_callback(app_ptr, event); }
void EventManager::callKeyEvent(Key key)
{
    KeyEvent event(key);
    callEvent(event);
}
