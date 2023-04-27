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
    ndWindow(int width, int height, const char* title);

    // Runtime
    void pollInputs(EventManager& event_manager);

    // Gets
    bool getShouldClose();

    // Sets
    void setShouldClose(bool value);

    // Log
    void printLog(int len);

    // Events
    void runEvent(Event& event);
};

#endif