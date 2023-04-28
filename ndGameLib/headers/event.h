#ifndef EVENT_H
#define EVENT_H

enum EventType
{
    None,
    KEY, RESIZE
};

enum Key
{
    ESCAPE_KEY
};

class Event
{
private:
    EventType type;

public:
    Event(EventType type_in);
};

// Key Event --------------------------------
class KeyEvent : public Event
{
private:
    Key key;

public:
    KeyEvent(Key key_in);
    Key getKey();
};

// Resize Event --------------------------------
class ResizeEvent : public Event
{
private:
    int width, height;

public:
    ResizeEvent(int wdth_in, int hght_in);
};

#endif