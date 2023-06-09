#ifndef EVENT_H
#define EVENT_H

enum class EventType
{
    NULL_TYPE,

    KEY, CLOSE, RESIZE, START_FRAME, END_FRAME,
    BEGIN_APP
};

enum class Key
{
    NULL_KEY,

    ESCAPE_KEY,
    COMMAND_KEY,
    W_KEY
};

class Event
{
private:
    EventType type;
    bool      active;

public:
    Event(EventType type_in);
    Event();
    EventType getType();
    virtual Key getKey();
    virtual int getWidth();
    virtual int getHeight();

    bool isNull();
};

// Key Event --------------------------------
class KeyEvent : public Event
{
private: Key key;
public:
    KeyEvent(Key key_in);
    KeyEvent();
    Key getKey();
};

// Resize Event --------------------------------
class ResizeEvent : public Event
{
private: int width, height;
public:
    ResizeEvent(int wdth_in, int hght_in);
    ResizeEvent();
    int getWidth();
    int getHeight();
};

#endif