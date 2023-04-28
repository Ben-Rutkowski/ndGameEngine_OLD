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
    Key getKey() { return key; }
};

// Resize Event --------------------------------
// class ResaizeEvent : public Event
// {
// private:
//     int width, height;

// public:
//     ResizeEvent(int wdth_in, int hght_in);
// };

#endif