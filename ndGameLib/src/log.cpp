#include "log.h"
#include <iostream>

// Initialization --------------------------------
Log::Log(Module mod_in) : counter{ 0 }, module{ mod_in } {}

// Recording --------------------------------
void Log::addSuccess(EntryOperation operation , bool success)
{
    log[counter].metaData(module, operation, EntryType::SUCCESS);
    log[counter].successData(success);
    counter++;
}

// Print --------------------------------
void Log::printLog(int len)
{
    for (int i=0; i<len; i++)
        log[i].printEntry();
}
