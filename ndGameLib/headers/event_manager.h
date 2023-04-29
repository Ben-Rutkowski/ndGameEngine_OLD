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
    void callStartFrameEvent();
    void callEndFrameEvent();
};

#endif

#ifdef EVENT_MANAGER_MACROS

#define CALL_TYPE_EVENT(TYPE, ...) \
    TYPE event(__VA_ARGS__); \
    callEvent(event); \

#define CALL_EVENT(TYPE) \
    Event event(TYPE); \
    callEvent(event); \

#endif