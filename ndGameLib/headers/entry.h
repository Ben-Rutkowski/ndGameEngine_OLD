#ifndef ENTRY_H
#define ENTRY_H

enum EntryType
{
    NULL_TYPE,

    SUCCESS
};

enum EntryOperation
{
    NULL_OPERATION,

    START_RUN_LOOP,
    INIT_GLFW,
    INIT_GLAD,
    CREATE_GLFW_WINDOW
};

enum Module
{
    NULL_MODULE,

    APPLICATION,
    WINDOW
};

class Entry
{
protected:
    int module, operation, type, data;

protected:
    void printModule();
    void printOperation();

    // Print
    void printSuccess();

public:
    Entry();

    // Print
    void printEntry();

    // Data
    void metaData(Module, EntryOperation, EntryType);
    void successData(bool success);
};

#endif