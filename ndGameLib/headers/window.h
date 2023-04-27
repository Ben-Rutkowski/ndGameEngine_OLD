#include "glad_glfw.h"
#include "log.h"

#ifndef WINDOW_H
#define WINDOW_H

class ndWindow
{
private:
    GLFWwindow* glfw_window;
    Log         log;
public:
    ndWindow(int width, int height, const char* title);

    // Log
    void printLog(int len);
};

#endif