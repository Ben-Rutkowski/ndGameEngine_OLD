#include "application.h"
#include <iostream>

ndApp::ndApp()
: log(APPLICATION) {}

// Init
void ndApp::attachWindow(ndWindow* window_in) { window = window_in; }

// Runloop --------------------------------
void ndApp::runApplication()
{
    while (!window->getShouldClose())
    {  
        log.addSuccess(START_RUN_LOOP, true);
        window->setShouldClose(true);
    }
}

// Log
void ndApp::printLog(int len) { log.printLog(len); }