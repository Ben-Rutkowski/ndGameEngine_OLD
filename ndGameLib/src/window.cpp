#include "window.h"
#include <iostream>

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
    glfw_window = glfwCreateWindow(width/2, height/2, title, NULL, NULL);
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

// Events --------------------------------
void ndWindow::pollInputs(EventManager& event_manager)
{
    if (isPressed(GLFW_KEY_ESCAPE))
        event_manager.callKeyEvent(Key::ESCAPE_KEY);
    else if (isPressed(GLFW_KEY_W))
        event_manager.callKeyEvent(Key::W_KEY);
    else
        event_manager.setControlKey(isPressed(GLFW_KEY_LEFT_SUPER));
}

void ndWindow::runEvent(Event& event)
{
    switch (event.getType())
    {
    case EventType::BEGIN_APP:   onBeginApp(event);   break;
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

// EVENTS 
void ndWindow::onKey(Event& event)
{
    if (event_manager->getControlKey())
        switch (event.getKey())
        {
        case Key::W_KEY : event_manager->queueEvent(EventType::CLOSE); break;
        default:;
        }
    else
        switch (event.getKey())
        {
        case Key::ESCAPE_KEY: break;
        default:;
        }
}

void ndWindow::onBeginApp(Event& event)
{
    
}

void ndWindow::onClose(Event& event)
{
    log.addSuccess(EntryOperation::CLOSE, true);
    setShouldClose(true);
}

void ndWindow::onResize(Event& event)
{
    width  = event.getWidth()*2;
    height = event.getHeight()*2;
    glViewport(0, 0, width, height);
}

void ndWindow::onStartFrame(Event& event)
{
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, width, height);
}

void ndWindow::onEndFrame(Event& event)
{
    glfwPollEvents();
    glfwSwapBuffers(glfw_window);
}

// STATIC
void ndWindow::resizeCallback(GLFWwindow* window, int width, int height) { getManager(window)->callResizeEvent(width, height); } 
void ndWindow::closeCallback(GLFWwindow* window)                         { getManager(window)->callCloseEvent(); }
EventManager* ndWindow::getManager(GLFWwindow* window)
{
    void* ptr = glfwGetWindowUserPointer(window);
    return static_cast<EventManager*>(ptr);
}
