#include "window.h"

// Initialization --------------------------------
ndWindow::ndWindow(int width, int height, const char* title)
: log(WINDOW), should_close{ false }
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

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        log.addSuccess(INIT_GLAD, false);
    else 
        log.addSuccess(INIT_GLAD, true);   
}          

// Events --------------------------------
void ndWindow::pollInputs(EventManager& event_manager)
{
    if (isPressed(GLFW_KEY_ESCAPE))
        event_manager.callKeyEvent(ESCAPE_KEY);
    if (true)
        event_manager.callKeyEvent(ESCAPE_KEY);
}

void ndWindow::runEvent(Event& event)
{
    log.addSuccess(TEST, true);
}

// Private --------------------------------
bool ndWindow::isPressed(int key) { return glfwGetKey(glfw_window, key) == GLFW_PRESS; }
