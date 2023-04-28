#include "glad_glfw.h"
#include "event_manager.h"
#include "log.h"

#ifndef WINDOW_H
#define WINDOW_H

class ndWindow
{
private:
    int width, height;
    GLFWwindow*   glfw_window;
    Log           log;

private:
    bool isPressed(int key);

    // Callbacks
    static void resizeCallback(GLFWwindow*, int, int);

public:
    // Initialization
    ndWindow(int width, int height, const char* title);
    void setCallbacks();
    void setEventManager(void* ptr);
    void setDimensions(int width_in, int height_in);
    void setShouldClose(bool value);
    bool getShouldClose();

    // Runtime
    void endLoopFrame();
    
    // Events
    void runEvent(Event& event);
    void pollInputs(EventManager& event_manager);

    // Log
    void printLog(int len);
};

#endif