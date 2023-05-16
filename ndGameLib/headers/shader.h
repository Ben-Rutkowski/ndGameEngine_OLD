#include "glad_glfw.h"
#include "log.h"
#include "vec.h"
#include "mat.h"
#include <string>

#ifndef SHADER_H
#define SHADER_H

enum class ShaderType
{
    VERTEX, FRAGMENT, GEOMETRY,

    LENGTH
};

class ndShaderProgram
{
private:
    Log log;
    unsigned int program_id;

    unsigned int vertex_id;
    unsigned int fragment_id;
    unsigned int geometry_id;

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
    void compileProgramGeo();

    // Uniforms
    void uniform1f(float value, const char* name);
    void uniform2f(vec2 value, const char* name);
    void uniform4x4f(mat4 value, const char* name);

    // Runtime
    void use();

    // Log
    void printLog();
};

#endif