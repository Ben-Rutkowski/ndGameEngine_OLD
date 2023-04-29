#include "glad_glfw.h"
#include "event_manager.h"
#include "log.h"

#ifndef WINDOW_H
#define WINDOW_H

class ndWindow
{
private:
    int width, height;
    EventManager* event_manager;
    GLFWwindow*   glfw_window;
    Log           log;

private:
    bool isPressed(int key);

    // On events
    void onKey(Event& );
    void onClose(Event&);
    void onResize(Event&);
    void onStartFrame(Event&);
    void onEndFrame(Event&);

    // STATIC
    static void resizeCallback(GLFWwindow*, int, int);
    static void closeCallback(GLFWwindow*);
    static EventManager* getManager(GLFWwindow*);

public:
    // Initialization
    ndWindow(int width, int height, const char* title);
    void setCallbacks();
    void setEventManager(void* ptr);
    void setDimensions(int width_in, int height_in);
    void setShouldClose(bool value);
    bool getShouldClose();
    
    // Events
    void runEvent(Event& event);
    void pollInputs(EventManager& event_manager);

    // Log
    void printLog(int len);
};

#endif