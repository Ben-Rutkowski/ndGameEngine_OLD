#include "compiled_shaders.h"

// Initialization --------------------------------
ndShaderProgram ShaderArray::word_program = ndShaderProgram();

void ShaderArray::compileShaders()
{
    word_program.attachShader(WORD_V, ShaderType::VERTEX);
    word_program.attachShader(WORD_G, ShaderType::GEOMETRY);
    word_program.attachShader(WORD_F, ShaderType::FRAGMENT);
    word_program.compileProgramGeo();
    word_program.printLog();
}

ndShaderProgram* ShaderArray::getWordProgram() { return &word_program; }