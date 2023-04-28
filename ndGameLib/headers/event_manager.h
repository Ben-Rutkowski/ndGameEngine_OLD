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
    void callEvent(Event& event);

public: 
    // Initialization
    EventManager(void* ptr);
    void setEventCallback(void* ptr);

    // Event
    void callKeyEvent(Key key);
    void callCloseEvent();
    void callResizeEvent(int width, int height);
};

#endif