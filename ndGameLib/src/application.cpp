#define APPLICATION_MACROS
#include "application.h"
#include "vao.h"
#include "shader_paths.h"

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
    float data[] = 
    {
        0.0, 0.0
    };

    unsigned int elements[] =
    {
        0
    };

    ndShaderProgram my_program;
    my_program.attachShader(TEST_V, ShaderType::VERTEX);
    my_program.attachShader(TEST_G, ShaderType::GEOMETRY);
    my_program.attachShader(TEST_F, ShaderType::FRAGMENT);
    my_program.compileProgramGeo();
    // my_program.compileProgram();

    VAO my_buffer;

    my_buffer.loadArrayStatic(sizeof(data), data);
    my_buffer.loadElementStatic(sizeof(elements), elements);
    my_buffer.addAttribPointerf(2, 0);

    beginApp();
    while (!window->getShouldClose())
    {
        startLoopFrame();
        pollInputs();

        my_buffer.drawPoints(1, my_program);

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