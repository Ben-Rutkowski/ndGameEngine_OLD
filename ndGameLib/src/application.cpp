#include "application.h"
#include <iostream>

// Constructor
ndApp::ndApp()
: log(APPLICATION) {}

// Init
void ndApp::attachWindow(ndWindow* window_in) { window = window_in; }

// Runloop --------------------------------
void ndApp::runApplication()
{
    log.addSuccess(START_RUN_LOOP, true);
    while (!window->getShouldClose())
    {  
        window->setShouldClose(true);
    }
}

// Log
void ndApp::printLog(int len) { log.printLog(len); }