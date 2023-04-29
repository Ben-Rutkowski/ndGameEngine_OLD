#include "event.h"

#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#define QUEUE_LEN 4
typedef void(*evt_call)(void*, Event&);

class EventCache
{
private:
    Event       event_queue[QUEUE_LEN];
    int         event_counter;
    ResizeEvent resize_queue;

private:
    void stepCount();

public:
    EventCache();
    void queueEvent(EventType type);
    void queueResizeEvent(int width, int height);
    Event*       getCurrentEvent();
    ResizeEvent* getCurrentResizeEvent();
    
    // Interface
    void reseEventCounter();
    void clearCurrentEvent();
    void clearCurrentResizeEvent();
};

class EventManager
{
private:
    EventCache cache;

    void*    app_ptr;
    evt_call event_callback;

private:
    void callEvent(Event& event);
    void callQueuedEvents();
    void callQueuedResizeEvents();

public: 
    // Initialization
    EventManager(void* ptr);
    void setEventCallback(void* ptr);

    // Cache
    void queueEvent(EventType type);
    void queueResizeEvent(int width, int height);
    void callQueue();

    // Event
    void callKeyEvent(Key key);
    void callResizeEvent(int width, int height);
    void callCloseEvent();
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