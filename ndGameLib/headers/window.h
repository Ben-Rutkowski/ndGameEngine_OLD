#include "glad_glfw.h"
#include "log.h"

#ifndef WINDOW_H
#define WINDOW_H

class ndWindow
{
private:
    Log         log;
    GLFWwindow* glfw_window;
    bool        should_close;
public:
    ndWindow(int width, int height, const char* title);

    // Gets
    bool getShouldClose();

    // Sets
    void setShouldClose(bool value);

    // Log
    void printLog(int len);

};

#endif