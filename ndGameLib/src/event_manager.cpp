#define EVENT_MANAGER_MACROS
#include "event_manager.h"

// Initialization --------------------------------
EventManager::EventManager(void* ptr) : app_ptr{ ptr } {}
void EventManager::setEventCallback(void* ptr)
{
    evt_call callback = (evt_call)ptr;
    event_callback = callback;
}

// Event --------------------------------
void EventManager::callCloseEvent()                       { CALL_EVENT(EventType::CLOSE); }
void EventManager::callStartFrameEvent()                  { CALL_EVENT(EventType::START_FRAME) }
void EventManager::callEndFrameEvent()                    { CALL_EVENT(EventType::END_FRAME) }
void EventManager::callKeyEvent(Key key)                  { CALL_TYPE_EVENT(KeyEvent, key) }
void EventManager::callResizeEvent(int width, int height) { CALL_TYPE_EVENT(ResizeEvent, width, height) }

// Private --------------------------------
void EventManager::callEvent(Event& event) { event_callback(app_ptr, event); }