#include "shader.h"

#ifndef VAO_H
#define VAO_H

class VAO
{
private:
    unsigned int vao, vbo, ebo;
    int attrib_index;

public:
    VAO();
    ~VAO();
    void loadArrayStatic(int size, void* data);
    void loadElementStatic(int size, void* data);
    void addAttribPointerf(int vec_size, int offset);

    // Rendering
    void drawTriangles(int triangle_num, ndShaderProgram& program);
};

#endif