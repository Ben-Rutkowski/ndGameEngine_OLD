#include "shader.h"

#ifndef SHADER_PATHS_H
#define SHADER_PATHS_H

// WORD
#define WORD_V "/Users/benjaminrutkowski/Projects/ndGameEngine/ndGameLib/shaders/word/vertex.vs"
#define WORD_G "/Users/benjaminrutkowski/Projects/ndGameEngine/ndGameLib/shaders/word/geometry.gs"
#define WORD_F "/Users/benjaminrutkowski/Projects/ndGameEngine/ndGameLib/shaders/word/fragment.fs"

class ShaderArray
{
private:
    static ndShaderProgram word_program;
    
public:
    static void compileShaders();
    
    static ndShaderProgram* getWordProgram();
};

#endif