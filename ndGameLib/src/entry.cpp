#include "entry.h"
#include <iostream>

// Entry --------------------------------
Entry::Entry()
: operation{ 0 }, module{ 0 }, type{ 0 }, data{ 0 } {}

void Entry::printModule()
{
    if (module == APPLICATION)
        std::cout << "APPLICATION::";
}

void Entry::printOperation()
{
    if (operation == START_APP)
        std::cout << "START_APP::";
    if (operation == START_RUN_LOOP)
        std::cout << "START_RUN_LOOP::";
}

// Print --------------------------------
void Entry::printEntry()
{
    if (type == SUCCESS)
        printSuccess();
}

void Entry::printSuccess()
{
    printModule();
    printOperation();
    
    if (data == 0x00000001)
        std::cout << " Success" << std::endl;
    else
        std::cout << " Failure" << std::endl;
}

// Data --------------------------------
void Entry::metaData(Module mod_in, Operation op_in, Type type_in)
{
    module    = mod_in;
    operation = op_in;
    type      = type_in;
}

void Entry::successData(bool success)
{
    if (success)
        data = 0x00000001;
}
