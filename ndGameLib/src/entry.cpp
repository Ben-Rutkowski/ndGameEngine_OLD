#include "entry.h"
#include <iostream>

// Initialization --------------------------------
Entry::Entry()
: type{ EntryType::NULL_TYPE },
  module{ Module::NULL_MODULE },
  operation{ EntryOperation::NULL_OPERATION },
  data{ 0 } {}

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

// Print --------------------------------
void Entry::printEntry()
{
    if (type == EntryType::SUCCESS)
        printSuccess();
}

// Private --------------------------------
void Entry::printSuccess()
{
    printModule();
    printOperation();
       
    switch (data)
    {
    case 0x00000001: std::cout << " Success" << std::endl; break;
    default:         std::cout << " Failure" << std::endl;
    }
}

void Entry::printModule()
{
    switch (module)
    {
    case Module::APPLICATION: std::cout << "APPLICATION::"; break;
    case Module::WINDOW:      std::cout << "WINDOW::";      break;
    default:;
    }
}

void Entry::printOperation()
{
    switch (operation)
    {
    case EntryOperation::START_RUN_LOOP:     std::cout << "START_RUN_LOOP::";     break;
    case EntryOperation::CLOSE:              std::cout << "CLOSE::";              break;
    case EntryOperation::INIT_GLFW:          std::cout << "INIT_GLFW::";          break;
    case EntryOperation::INIT_GLAD:          std::cout << "INIT_GLAD::";          break;
    case EntryOperation::CREATE_GLFW_WINDOW: std::cout << "CREATE_GLFW_WINDOW::"; break;
    case EntryOperation::TEST:               std::cout << "TEST::";               break;
    default:;
    }
}