#ifndef EVENT_H
#define EVENT_H

enum class EventType
{
    KEY, CLOSE, RESIZE, START_FRAME, END_FRAME
};

enum class Key
{
    NULL_KEY,

    ESCAPE_KEY
};

class Event
{
private: EventType type;
public:
    Event(EventType type_in);
    EventType getType();
    virtual Key getKey();
    virtual int getWidth();
    virtual int getHeight();
};

// Key Event --------------------------------
class KeyEvent : public Event
{
private: Key key;
public:
    KeyEvent(Key key_in);
    Key getKey();
};

// Resize Event --------------------------------
class ResizeEvent : public Event
{
private: int width, height;
public:
    ResizeEvent(int wdth_in, int hght_in);
    int getWidth();
    int getHeight();
};

#endif