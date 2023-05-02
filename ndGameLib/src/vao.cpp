#include "vao.h"
#include "glad_glfw.h"

// Initialization --------------------------------
VAO::VAO()
{
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
}

VAO::~VAO()
{
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
}

// Rendering --------------------------------
void VAO::draw(ndShaderProgram& program) {}