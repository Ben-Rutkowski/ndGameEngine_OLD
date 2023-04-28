#ifndef ENTRY_H
#define ENTRY_H

enum class EntryType
{
    NULL_TYPE,

    SUCCESS
};

enum class EntryOperation
{
    NULL_OPERATION,

    START_RUN_LOOP, CLOSE,
    INIT_GLFW, INIT_GLAD,
    CREATE_GLFW_WINDOW,
    TEST
};

enum class Module
{
    NULL_MODULE,

    APPLICATION,
    WINDOW
};

class Entry
{
protected:
    EntryType      type;
    Module         module;
    EntryOperation operation;
    int            data;

protected:
    void printModule();
    void printOperation();
    void printSuccess();

public:
    // Initialization
    Entry();
    void metaData(Module, EntryOperation, EntryType);
    void successData(bool success);

    // Print
    void printEntry();    
};

#endif