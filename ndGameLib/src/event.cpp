#include "event.h"

// Event --------------------------------
Event::Event(EventType type_in) : type{ type_in } {}
EventType Event::getType()   { return type; }
Key       Event::getKey()    { return Key::NULL_KEY; }
int       Event::getWidth()  { return 0; }
int       Event::getHeight() { return 0; }

// Key Event --------------------------------
KeyEvent::KeyEvent(Key key_in) : Event(EventType::KEY), key{ key_in } {}
Key KeyEvent::getKey() { return key; }

// Resize Event --------------------------------
ResizeEvent::ResizeEvent(int wdth_in, int hght_in)
: Event(EventType::RESIZE), 
  width{ wdth_in },
  height{ hght_in } {}
  
int ResizeEvent::getWidth()  { return width; }
int ResizeEvent::getHeight() { return height; }