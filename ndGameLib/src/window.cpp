#include "window.h"

// Initialization --------------------------------
ndWindow::ndWindow(int width_in, int height_in, const char* title)
: log(Module::WINDOW), width{ width_in }, height{ height_in }
{
    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    log.addSuccess(EntryOperation::INIT_GLFW, true);

    // Create GLFW window
    glfw_window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (glfw_window == NULL)
        log.addSuccess(EntryOperation::CREATE_GLFW_WINDOW, false);
    else
        log.addSuccess(EntryOperation::CREATE_GLFW_WINDOW, true);

    // Set current window 
    glfwMakeContextCurrent(glfw_window);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        log.addSuccess(EntryOperation::INIT_GLAD, false);
    else 
        log.addSuccess(EntryOperation::INIT_GLAD, true);  
}

void ndWindow::setCallbacks()
{
    glfwSetWindowSizeCallback(glfw_window, ndWindow::resizeCallback);
}

void ndWindow::setEventManager(void* ptr)  { glfwSetWindowUserPointer(glfw_window, ptr); }
void ndWindow::setShouldClose(bool value) { glfwSetWindowShouldClose(glfw_window, true); }
bool ndWindow::getShouldClose()           { return glfwWindowShouldClose(glfw_window); }
void ndWindow::setDimensions(int width_in, int height_in) 
{
    width  = width_in;
    height = height_in;
}

// Runtime --------------------------------
void ndWindow::endLoopFrame()
{
    glfwPollEvents();
    glfwSwapBuffers(glfw_window);
}

// Events --------------------------------
void ndWindow::pollInputs(EventManager& event_manager)
{
    if (isPressed(GLFW_KEY_ESCAPE))
        event_manager.callKeyEvent(Key::ESCAPE_KEY);
}

void ndWindow::runEvent(Event& event)
{
    setShouldClose(true);
}

// Log --------------------------------
void ndWindow::printLog(int len) { log.printLog(len); }

// Private --------------------------------
bool ndWindow::isPressed(int key) { return glfwGetKey(glfw_window, key) == GLFW_PRESS; }

// STATIC Callbacks
void ndWindow::resizeCallback(GLFWwindow* window, int width, int height)
{
    void* ptr = glfwGetWindowUserPointer(window);
    EventManager* event_manager = static_cast<EventManager*>(ptr);
    event_manager->callResize(width, height);
} 
