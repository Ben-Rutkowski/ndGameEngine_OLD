#include "log.h"
#include <iostream>

// Constructor
Log::Log()
: counter{ 0 } {}

// Recording --------------------------------
void Log::addSuccess(Module module, Operation operation , bool success)
{
    log[counter].metaData(module, operation, SUCCESS);
    log[counter].successData(success);
    counter++;
}

// Print --------------------------------
void Log::printLog(int len)
{
    for (int i=0; i<len; i++)
        log[i].printEntry();
}
