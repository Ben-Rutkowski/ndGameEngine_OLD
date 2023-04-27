#include "event.h"

#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

typedef void(*evt_call)(void*, Event&);

class EventManager
{
private:
    void*    app_ptr;
    evt_call event_callback;

private:
    void callEvent(Event& event) { event_callback(app_ptr, event); }

public: 
    // Initialization
    EventManager(void* ptr);
    void setEventCallback(void* ptr);

    // Event
    void callKeyEvent(Key key);
};

#endif