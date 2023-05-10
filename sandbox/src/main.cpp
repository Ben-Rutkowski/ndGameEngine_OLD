#include "ndGameCore.h"
#include "compiled_shaders.h"
#include "mat.h"
#include <iostream>

int main()
{
    ndApp    app;
    ndWindow window(WIDTH, HEIGHT, TITLE);
    ShaderArray::compileShaders();

    app.attachWindow(&window);

    app.init();
    app.runApplication();

    // app.printLog(512);
    // window.printLog(512);
}