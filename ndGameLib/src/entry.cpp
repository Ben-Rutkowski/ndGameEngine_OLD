#include "entry.h"
#include <iostream>

// Entry --------------------------------
Entry::Entry()
: operation{ 0 }, module{ 0 }, type{ 0 }, data{ 0 } {}

void Entry::printModule()
{
    switch (module)
    {
    case APPLICATION:
        std::cout << "APPLICATION::";
        break;
    case WINDOW:
        std::cout << "WINDOW::";
        break;
    }
}

void Entry::printOperation()
{
    switch (operation)
    {
    case START_RUN_LOOP:
        std::cout << "START_RUN_LOOP::";
        break;
    case INIT_GLFW:
        std::cout << "INIT_GLFW::";
        break;
    case INIT_GLAD:
        std::cout << "INIT_GLAD::";
        break;
    case CREATE_GLFW_WINDOW:
        std::cout << "CREATE_GLFW_WINDOW::";
        break;
    }
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
void Entry::metaData(Module mod_in, EntryOperation op_in, EntryType type_in)
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
