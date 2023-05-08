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

void VAO::addAttribPointerf(int index, int vec_size, int data_size, int offset)
{
    void* vec_offset = (void*)(offset * sizeof(float));

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(index, vec_size, GL_FLOAT, GL_FALSE, data_size, vec_offset);
    glEnableVertexAttribArray(index);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);  
}

// Rendering --------------------------------
void VAO::drawTriangles(int triangle_num, ndShaderProgram* program)
{
    int element_num = 3 * triangle_num;
    program->use();
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, element_num, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void VAO::drawPoints(int point_num, ndShaderProgram* program)
{
    program->use();
    glBindVertexArray(vao);
    glDrawArrays(GL_POINTS, 0, point_num);
    glBindVertexArray(0);
}