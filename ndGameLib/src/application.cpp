#define APPLICATION_MACROS
#include "application.h"
#include "shader.h"
#include "vao.h"

const char* test_vertex   = "/Users/benjaminrutkowski/Projects/ndGameEngine/ndGameLib/shaders/test/vertex.vs";
const char* test_fragment = "/Users/benjaminrutkowski/Projects/ndGameEngine/ndGameLib/shaders/test/fragment.fs";

// Initialization --------------------------------
ndApp::ndApp()
: log(Module::APPLICATION), event_manager(this) {}

void ndApp::attachWindow(ndWindow* window_in)
{
    window = window_in;
    window->setEventManager(&event_manager);
    window->setCallbacks();
}

void ndApp::init() { setEventCallback(); }

// Runtime --------------------------------
void ndApp::runApplication()
{
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0
    };

    unsigned int elements[] = {
        0, 1, 2
    };

    VAO vao;
    vao.loadArrayStatic(sizeof(vertices), vertices);
    vao.loadElementStatic(sizeof(elements), elements);
    vao.addAttribPointerf(3, 0);

    ndShaderProgram program;
    program.attachShader(test_vertex, ShaderType::VERTEX);
    program.attachShader(test_fragment, ShaderType::FRAGMENT);
    program.compileProgram();
    program.printLog();

    beginApp();
    while (!window->getShouldClose())
    {
        startLoopFrame();
        pollInputs();

        vao.drawTriangles(1, program);
        
        endLoopFrame();
    }
}

// Log --------------------------------
void ndApp::printLog(int len) { log.printLog(len); }

// Private --------------------------------
void ndApp::beginApp()                    { event_manager.callBeginAppEvent(); }
void ndApp::startLoopFrame()              { event_manager.callStartFrameEvent(); }
void ndApp::endLoopFrame()                { event_manager.callEndFrameEvent(); }
void ndApp::pollInputs()
{
    window->pollInputs(event_manager);
    event_manager.callQueue();
}
void ndApp::distributeEvent(Event& event) 
{
    window->runEvent(event);
}

// Set callbacks
void ndApp::setEventCallback()
{
    CAST_VOID(ndApp::eventCallback, callback)
    event_manager.setEventCallback(callback);
}

// STATIC 
void ndApp::eventCallback(void* ptr, Event& event)
{
    CAST_APP(ptr, app)
    app->distributeEvent(event);
}