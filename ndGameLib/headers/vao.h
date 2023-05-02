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

    // Rendering
    void draw(ndShaderProgram& program);
};

#endif