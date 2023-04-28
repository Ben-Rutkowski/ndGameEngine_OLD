#include "event.h"

// Event --------------------------------
Event::Event(EventType type_in) : type{ type_in } {}

// Key Event --------------------------------
KeyEvent::KeyEvent(Key key_in) : Event(KEY), key{ key_in } {}
Key KeyEvent::getKey() { return key; }

// Resize Event --------------------------------
ResizeEvent::ResizeEvent(int wdth_in, int hght_in)
: Event(RESIZE), width{ wdth_in }, height{ hght_in } {}