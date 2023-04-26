#ifndef ENTRY_H
#define ENTRY_H

enum Type
{
    NULL_TYPE,

    SUCCESS
};

enum Operation
{
    NULL_OPERATION,

    START_APP,
    START_RUN_LOOP
};

enum Module
{
    NULL_MODULE,

    APPLICATION
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
    void metaData(Module, Operation, Type);
    void successData(bool success);
};

#endif