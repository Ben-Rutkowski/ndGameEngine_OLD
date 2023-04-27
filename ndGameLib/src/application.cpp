#include "application.h"
#include <iostream>

ndApp::ndApp()
: log(APPLICATION) {}

// Init
void ndApp::attachWindow(ndWindow* window_in) { window = window_in; }

// Runloop --------------------------------
void ndApp::runApplication()
{
    bool run = true;
    while (run)
    {  
        log.addSuccess(START_RUN_LOOP, true);
        run = false;
    }
}

// Log
void ndApp::printLog(int len) { log.printLog(len); }