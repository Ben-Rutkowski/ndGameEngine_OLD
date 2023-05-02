#include "shader.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Initialization --------------------------------
ndShaderProgram::ndShaderProgram() : log{ Module::SHADER } {}
void ndShaderProgram::attachShader(const char* file_path, ShaderType type)
{
    unsigned int* shader_id   = getId(type);
    std::string   code_string = openShaderFile(file_path);
    
    // Compile shader
    const char* code = code_string.c_str();
    *shader_id = glCreateShader(getGLType(type));
    glShaderSource(*shader_id, 1, &code, NULL);
    glCompileShader(*shader_id);

    // Check complied
    logShaderCompiled(*shader_id);
}

void ndShaderProgram::compileProgram()
{
    // Comiple program
    program_id = glCreateProgram();
    glAttachShader(program_id, vertex_id);
    glAttachShader(program_id, fragment_id);
    glLinkProgram(program_id);

    // Check compiled
    logProgramCompiled();

    // Delete shaders
    glDeleteShader(vertex_id);
    glDeleteShader(fragment_id);
}

// Runtime
void ndShaderProgram::use() { glUseProgram(program_id); }

// Log
void ndShaderProgram::printLog() { log.printLog(512); }

// Private --------------------------------
void ndShaderProgram::logProgramCompiled()
{
    int  success;
    char info_log[512];
    glGetProgramiv(program_id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(program_id, 512, NULL, info_log);
        log.addSuccessLog(EntryOperation::LINK_SHADER_PROGRAM, false, info_log);
    }
    else
        log.addSuccess(EntryOperation::LINK_SHADER_PROGRAM, true);
}

void ndShaderProgram::logShaderCompiled(unsigned int id)
{
    int  success;
    char info_log[512];
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(id, 512, NULL, info_log);
        log.addSuccessLog(EntryOperation::COMPILE_SHADER, false, info_log);
    }
    else
        log.addSuccess(EntryOperation::COMPILE_SHADER, true);
}

int ndShaderProgram::getGLType(ShaderType type)
{
    switch (type)
    {
        case ShaderType::VERTEX:   return GL_VERTEX_SHADER; break;
        case ShaderType::FRAGMENT: return GL_FRAGMENT_SHADER; break;
        default: return 0;
    }
}

unsigned int* ndShaderProgram::getId(ShaderType type)
{
    switch (type)
    {
    case ShaderType::VERTEX:   return &vertex_id; break;
    case ShaderType::FRAGMENT: return &fragment_id; break;
    default: return (unsigned int*)0;
    }
}

std::string ndShaderProgram::openShaderFile(const char* file_path)
{
    std::ifstream     file;
    std::stringstream file_stream; 
    std::string       code_string;

    file.exceptions( std::ifstream::failbit | std::ifstream::badbit );
    try
    {
        file.open(file_path);
        file_stream << file.rdbuf();
        file.close();
        code_string = file_stream.str();
        log.addSuccess(EntryOperation::READ_SHADER_FILE, true);
    }
    catch (std::ifstream::failure e)
    {
        log.addSuccess(EntryOperation::READ_SHADER_FILE, false);
    }

    return code_string;
}