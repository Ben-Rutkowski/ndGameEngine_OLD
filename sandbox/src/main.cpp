#include "ndGameCore.h"
#include "shader.h"
#include <iostream>

int main()
{
    ndApp    app;
    ndWindow window(WIDTH, HEIGHT, TITLE);
    app.attachWindow(&window);

    app.init();
    app.runApplication();

    // app.printLog(512);
    // window.printLog(512);
}