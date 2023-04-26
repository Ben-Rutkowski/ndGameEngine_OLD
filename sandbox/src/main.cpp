#include "ndGameCore.h"
#include "log.h"
#include <iostream>

int main()
{
    ndApp app;

    app.runApplication();

    app.displayLog(512);
}