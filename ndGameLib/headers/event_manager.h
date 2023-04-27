#include "event.h"

#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

typedef void(*evt_call)(void*, Event&);

class EventManager
{
private:
    void*    app_ptr;
    evt_call event_callback;

public: 
    EventManager(void* ptr) : app_ptr{ ptr } {}

    // Sets
    void setEventCallback(void* ptr);

    // Event
    void callEvent(Event& event);
    void callKeyEvent(Key key);
};

#endif