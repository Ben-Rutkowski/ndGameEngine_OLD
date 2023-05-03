#include "vao.h"
#include "glad_glfw.h"

// Initialization --------------------------------
VAO::VAO() : attrib_index{ 0 }
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

void VAO::loadArrayStatic(int size, void* data)
{
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void VAO::loadElementStatic(int size, void* data)
{
    glBindVertexArray(vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    glBindVertexArray(0);
}

void VAO::addAttribPointerf(int vec_size, int offset)
{
    void* data_offset = (void*)(offset * sizeof(float));
    int   data_size   = vec_size * sizeof(float);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(attrib_index, vec_size, GL_FLOAT, GL_FALSE, data_size, data_offset);
    glEnableVertexAttribArray(attrib_index);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    attrib_index++;    
}

// Rendering --------------------------------
void VAO::drawTriangles(int triangle_num, ndShaderProgram& program)
{
    int element_num = 3 * triangle_num;
    program.use();
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, element_num, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}