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
    glfwSetWindowCloseCallback(glfw_window, ndWindow::closeCallback);
}

void ndWindow::setShouldClose(bool value) { glfwSetWindowShouldClose(glfw_window, true); }
bool ndWindow::getShouldClose()           { return glfwWindowShouldClose(glfw_window); }
void ndWindow::setEventManager(void* ptr)
{
    event_manager = (EventManager*)ptr;
    glfwSetWindowUserPointer(glfw_window, ptr);
}

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
    switch (event.getType())
    {
    case EventType::KEY:         onKey(event);        break;
    case EventType::CLOSE:       onClose(event);      break;
    case EventType::RESIZE:      onResize(event);     break;
    case EventType::START_FRAME: onStartFrame(event); break;
    case EventType::END_FRAME:   onEndFrame(event);   break;
    default:;
    }
}

// Log --------------------------------
void ndWindow::printLog(int len) { log.printLog(len); }

// PRIVATE --------------------------------
bool ndWindow::isPressed(int key) { return glfwGetKey(glfw_window, key) == GLFW_PRESS; }

// EVENTS ++++++++++++++++++++++++++++++++
void ndWindow::onKey(Event& event)
{
    switch (event.getKey())
    {
    case Key::ESCAPE_KEY: event_manager->callCloseEvent(); break;
    default:;
    }
}

void ndWindow::onClose(Event& event)
{
    log.addSuccess(EntryOperation::CLOSE, true);
    setShouldClose(true);
}

void ndWindow::onResize(Event& event)
{
    width  = event.getWidth();
    height = event.getHeight();
}

void ndWindow::onStartFrame(Event& event) {}
void ndWindow::onEndFrame(Event& event)
{
    glfwPollEvents();
    glfwSwapBuffers(glfw_window);
}
// +++++++++++++++++++++++++++++++++++++++

// STATIC
void ndWindow::resizeCallback(GLFWwindow* window, int width, int height) { getManager(window)->callResizeEvent(width, height); } 
void ndWindow::closeCallback(GLFWwindow* window)                         { getManager(window)->callCloseEvent(); }
EventManager* ndWindow::getManager(GLFWwindow* window)
{
    void* ptr = glfwGetWindowUserPointer(window);
    return static_cast<EventManager*>(ptr);
}
