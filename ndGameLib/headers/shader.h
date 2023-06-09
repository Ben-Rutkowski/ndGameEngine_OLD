#include "glad_glfw.h"
#include "log.h"
#include <string>

#ifndef SHADER_H
#define SHADER_H

enum class ShaderType
{
    VERTEX, FRAGMENT,

    LENGTH
};

class ndShaderProgram
{
private:
    Log log;
    unsigned int program_id;
    unsigned int vertex_id;
    unsigned int fragment_id;

private:
    void          logProgramCompiled();
    void          logShaderCompiled(unsigned int id);
    int           getGLType(ShaderType);
    unsigned int* getId(ShaderType);
    std::string   openShaderFile(const char* file_path);

public:
    ndShaderProgram();
    void attachShader(const char* file_path, ShaderType type);
    void compileProgram();

    // Runtime
    void use();

    // Log
    void printLog();
};

#endif