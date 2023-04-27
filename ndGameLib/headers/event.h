#ifndef EVENT_H
#define EVENT_H

class Event
{
public:
    Event() {}
};

// Key Event --------------------------------
enum Key
{
    ESCAPE_KEY
};

class KeyEvent : public Event
{
private:
    Key key;

public:
    KeyEvent(Key key_in) : key{ key_in } {}

    // Sets
    Key getKey() { return key; }
};

#endif