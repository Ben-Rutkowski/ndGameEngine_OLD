#include "application.h"
#include <iostream>

// Runloop --------------------------------
void ndApp::runApplication()
{
    log.addSuccess(APPLICATION, START_APP, true);
    bool run = true;
    while (run)
    {  
        log.addSuccess(APPLICATION, START_RUN_LOOP, true);
        run = false;
    }
}

// Log
void ndApp::displayLog(int len) { log.printLog(len); }