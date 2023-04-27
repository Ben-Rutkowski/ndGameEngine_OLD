#include "ndGameCore.h"
#include "glad_glfw.h"

int main()
{
    ndApp    app;
    ndWindow window(WIDTH, HEIGHT, TITLE);

    app.attachWindow(&window);

    app.runApplication();

    app.printLog(512);
    window.printLog(512);
}