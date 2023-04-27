#include "glad_glfw.h"
#include "log.h"
#include "event_manager.h"

#ifndef WINDOW_H
#define WINDOW_H

class ndWindow
{
private:
    Log         log;
    GLFWwindow* glfw_window;
    bool        should_close;

private:
    bool isPressed(int key);

public:
    // Initialization
    ndWindow(int width, int height, const char* title);
    void setShouldClose(bool value) { should_close = value; }
    bool getShouldClose()           { return should_close; }
    
    // Events
    void runEvent(Event& event);
    void pollInputs(EventManager& event_manager);

    // Log
    void printLog(int len) { log.printLog(len); }

};

#endif