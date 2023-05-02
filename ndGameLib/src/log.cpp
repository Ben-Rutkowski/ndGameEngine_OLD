#include "log.h"
#include <iostream>

// Entry ++++++++++++++++++++++++++++++++
// Initialization --------------------------------
Log::Log(Module mod_in) : counter{ 0 }, module{ mod_in } {}

// Recording --------------------------------
void Log::addSuccess(EntryOperation operation , bool success)
{
    log[counter].metaData(module, operation, EntryType::SUCCESS);
    log[counter].successData(success);
    counter++;
}

void Log::addSuccessLog(EntryOperation operation, bool success, char* info_log)
{
    log[counter].metaData(module, operation, EntryType::SUCCESS_LOG);
    log[counter].successData(success);
    log[counter].addInfoLog(info_log, 512);
    counter++;
}

// Print --------------------------------
void Log::printLog(int len)
{
    for (int i=0; i<len; i++)
        log[i].printEntry();
    std::cout << std::endl;
}
