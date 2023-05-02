#ifndef ENTRY_H
#define ENTRY_H

enum class EntryType
{
    NULL_TYPE,

    SUCCESS,
    SUCCESS_LOG
};

enum class EntryOperation
{
    NULL_OPERATION,

    START_RUN_LOOP, CLOSE,
    INIT_GLFW, INIT_GLAD,
    CREATE_GLFW_WINDOW,
    READ_SHADER_FILE,
    COMPILE_SHADER,
    LINK_SHADER_PROGRAM,
    TEST
};

enum class Module
{
    NULL_MODULE,

    APPLICATION,
    WINDOW,
    SHADER
};

class Entry
{
protected:
    EntryType      type;
    Module         module;
    EntryOperation operation;
    int            data;
    char           info_log[512];
    char           entry_name[32];

protected:
    void printModule();
    void printEntryName();
    void printOperation();
    void printSuccess();
    void printInfoLog();

public:
    // Initialization
    Entry();
    void metaData(Module, EntryOperation, EntryType);
    void successData(bool success);
    void addName(char* name, int len);
    void addInfoLog(char* log, int len);

    // Print
    void printEntry();    
};

#endif

#ifdef ENTRY_MACROS

#define OPERATION_CASE(OPERATION) \
    case EntryOperation::OPERATION: \
    { \
        std::cout << #OPERATION; \
        break; \
    } \

#define MODULE_CASE(MODULE) \
    case Module::MODULE: \
    { \
        std::cout << #MODULE << "::"; \
        break; \
    } \

#endif