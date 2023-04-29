#define EVENT_MANAGER_MACROS
#include "event_manager.h"

// Event Cache
// Initialization --------------------------------
EventCache::EventCache() : event_counter{ 0 } {}
void EventCache::queueEvent(EventType type)
{
    event_queue[event_counter] = Event(type);
    event_counter++;
}
void         EventCache::queueResizeEvent(int width, int height) { resize_queue = ResizeEvent(width, height); }
Event*       EventCache::getCurrentEvent()                       { return &event_queue[event_counter]; }
ResizeEvent* EventCache::getCurrentResizeEvent()                 { return &resize_queue; }

// Interface --------------------------------
void EventCache::reseEventCounter()            { event_counter = 0; }
void EventCache::clearCurrentEvent()       { event_queue[event_counter] = Event(); event_counter++; }
void EventCache::clearCurrentResizeEvent() { resize_queue = ResizeEvent(); }

// Private --------------------------------
void EventCache::stepCount() { event_counter = (event_counter+1)%QUEUE_LEN; }


// EventManager
// Initialization --------------------------------
EventManager::EventManager(void* ptr) : app_ptr{ ptr } {}
void EventManager::setEventCallback(void* ptr)
{
    evt_call callback = (evt_call)ptr;
    event_callback    = callback;
}

// Cache --------------------------------
void EventManager::queueEvent(EventType type)              { cache.queueEvent(type); }
void EventManager::queueResizeEvent(int width, int height) { cache.queueResizeEvent(width, height); }
void EventManager::callQueue()
{
    callQueuedEvents();
    callQueuedResizeEvents();
}


// Event --------------------------------
void EventManager::callCloseEvent()                       { CALL_EVENT(EventType::CLOSE); }
void EventManager::callStartFrameEvent()                  { CALL_EVENT(EventType::START_FRAME) }
void EventManager::callEndFrameEvent()                    { CALL_EVENT(EventType::END_FRAME) }
void EventManager::callKeyEvent(Key key)                  { CALL_TYPE_EVENT(KeyEvent, key) }
void EventManager::callResizeEvent(int width, int height) { CALL_TYPE_EVENT(ResizeEvent, width, height) }

// Private --------------------------------
void EventManager::callEvent(Event& event) { event_callback(app_ptr, event); }
void EventManager::callQueuedEvents()
{
    cache.reseEventCounter();
    Event* current_event = cache.getCurrentEvent();
    while (!current_event->isNull())
    {
        callEvent(*current_event);
        cache.clearCurrentEvent();
        current_event = cache.getCurrentEvent();
    }
}

void EventManager::callQueuedResizeEvents()
{
    ResizeEvent* current_event = cache.getCurrentResizeEvent();
    while (!current_event->isNull())
    {
        callEvent(*current_event);
        cache.clearCurrentResizeEvent();
        current_event = cache.getCurrentResizeEvent();
    }
}