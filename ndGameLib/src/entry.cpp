#define  ENTRY_MACROS
#include "entry.h"
#include <iostream>

// Entry ++++++++++++++++++++++++++++++++
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

void Entry::successData(bool success) { if(success) { data = 0x00000001; } }
void Entry::addInfoLog(char* log, int len)
{
    for (int i=0; i<len; i++)
        info_log[i] = log[i];
}

void Entry::addName(char* name, int len)
{
    for (int i=0; i<len; i++)
        entry_name[i] = name[i];
}

// Print --------------------------------
void Entry::printEntry()
{
    switch (type)
    {
    case EntryType::SUCCESS:     printSuccess(); break;
    case EntryType::SUCCESS_LOG: printSuccess();  break;
    default:;
    }
}

// Private --------------------------------
void Entry::printSuccess()
{
    printModule();
    // printEntryName();
    printOperation();
       
    switch (data)
    {
    case 0x00000001: std::cout << std::endl; break;
    default:         std::cout << "Failure" << std::endl;
    }

    // printInfoLog();
}

void Entry::printModule()
{
    switch (module)
    {
    MODULE_CASE(APPLICATION)
    MODULE_CASE(WINDOW)
    MODULE_CASE(SHADER)
    default:;
    }
}

void Entry::printOperation()
{
    switch (operation)
    {
    OPERATION_CASE(START_RUN_LOOP)
    OPERATION_CASE(CLOSE)
    OPERATION_CASE(INIT_GLFW)
    OPERATION_CASE(INIT_GLAD)
    OPERATION_CASE(CREATE_GLFW_WINDOW)
    OPERATION_CASE(READ_SHADER_FILE)
    OPERATION_CASE(COMPILE_SHADER)
    OPERATION_CASE(LINK_SHADER_PROGRAM)
    OPERATION_CASE(TEST)
    default:;
    }
}

void Entry::printInfoLog()
{
    if (info_log[0] != '\0')
        std::cout << info_log << std::endl;
}

void Entry::printEntryName()
{
    if (entry_name[0] != '\0')
        std::cout << entry_name << "::" << std::endl;
}