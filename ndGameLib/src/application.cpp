#include "application.h"
#include <iostream>

ndApp::ndApp()
: log(APPLICATION) {}

// Init
void ndApp::attachWindow(ndWindow* window_in) { window = window_in; }

// Runloop --------------------------------
void ndApp::runApplication()
{
    log.addSuccess(START_APP, true);
    bool run = true;
    while (run)
    {  
        log.addSuccess(START_RUN_LOOP, true);
        run = false;
    }
}

// Log
void ndApp::displayLog(int len) { log.printLog(len); }