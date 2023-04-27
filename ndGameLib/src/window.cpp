#include "window.h"

// Constructor --------------------------------
ndWindow::ndWindow(int width, int height, const char* title)
: log(WINDOW)
{
    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    log.addSuccess(INIT_GLFW, true);

    // Create GLFW window
    glfw_window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (glfw_window == NULL)
        log.addSuccess(CREATE_GLFW_WINDOW, false);
    else
        log.addSuccess(CREATE_GLFW_WINDOW, true);

    glfwMakeContextCurrent(glfw_window);

    // Init GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        log.addSuccess(INIT_GLAD, false);
    else 
        log.addSuccess(INIT_GLAD, true);   
}

// Log --------------------------------
void ndWindow::printLog(int len) { log.printLog(len); }