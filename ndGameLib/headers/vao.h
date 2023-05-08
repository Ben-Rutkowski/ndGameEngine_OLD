#include "shader.h"

#ifndef VAO_H
#define VAO_H

class VAO
{
private:
    unsigned int vao, vbo, ebo;

public:
    VAO();
    ~VAO();
    void loadArrayStatic(int size, void* data);
    void loadElementStatic(int size, void* data);
    void addAttribPointerf(int index, int vec_size, int data_size, int offset);

    // Rendering
    void drawTriangles(int triangle_num, ndShaderProgram* program);
    void drawPoints(int point_num, ndShaderProgram* program);
};

#endif