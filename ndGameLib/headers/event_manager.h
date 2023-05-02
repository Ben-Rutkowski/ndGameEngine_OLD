#include "event.h"

#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#define QUEUE_LEN 4
typedef void(*evt_call)(void*, Event&);

// Event Cache ++++++++++++++++++++++++++++++++
class EventCache
{
private:
    Event       event_queue[QUEUE_LEN];
    ResizeEvent resize_queue;
    int         event_counter;
    int         resize_event_counter;

private:
    void stepCount();

public:
    EventCache();
    void queueEvent(EventType type);
    void queueResizeEvent(int width, int height);
    Event*       getCurrentEvent();
    ResizeEvent* getCurrentResizeEvent();
    
    // Interface
    void resetEventCounter();
    void clearCurrentEvent();
    void resetResizeEventCounter();
    void clearCurrentResizeEvent();
};

// EventManager ++++++++++++++++++++++++++++++++
class EventManager
{
private:
    EventCache cache;
    bool       control_key;

    void*    app_ptr;
    evt_call event_callback;

private:
    void callEvent(Event& event);
    void callQueuedEvents();
    void callQueuedResizeEvents();

public: 
    // Initialization
    EventManager(void* ptr);
    void setControlKey(bool press);
    void setEventCallback(void* ptr);
    bool getControlKey();

    // Cache
    void queueEvent(EventType type);
    void queueResizeEvent(int width, int height);
    void callQueue();

    // Event
    void callKeyEvent(Key key);
    void callResizeEvent(int width, int height);
    void callBeginAppEvent();
    void callCloseEvent();
    void callStartFrameEvent();
    void callEndFrameEvent();
};

#endif

// Macros ++++++++++++++++++++++++++++++++
#ifdef EVENT_MANAGER_MACROS

#define CALL_TYPE_EVENT(TYPE, ...) \
    TYPE event(__VA_ARGS__); \
    callEvent(event); \

#define CALL_EVENT(TYPE) \
    Event event(TYPE); \
    callEvent(event); \

#define CALL_QUEUE(RESET_COUNTER, GET_CURRENT, CLEAR_CURRENT) \
    cache.RESET_COUNTER; \
    Event* current_event = cache.GET_CURRENT; \
    while (!current_event->isNull()) \
    { \
        callEvent(*current_event); \
        cache.CLEAR_CURRENT; \
        current_event = cache.GET_CURRENT; \
    } \

#endif