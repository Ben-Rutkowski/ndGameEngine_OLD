#include "ndGameCore.h"
#include "shader.h"

int main()
{
    ndApp    app;
    ndWindow window(WIDTH, HEIGHT, TITLE);
    app.attachWindow(&window);

    ndShaderProgram program;
    program.attachShader(test_vertex, ShaderType::VERTEX);

    app.init();
    app.runApplication();

    app.printLog(512);
    window.printLog(512);
}