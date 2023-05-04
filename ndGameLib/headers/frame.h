#include "shader.h"
#include "vao.h"

#ifndef FRAME_H
#define FRAME_H

// TODO:
// Header: a array of words
// Popup box: a single window with a list of options
// In frame optiions: sliders, check-box, number fill-in, color selection,
//                    mode select, window/layer system, scroll wheel               

class ndFrame
{
private:
    VAO vao;
    float width, height;
    float x_pos, y_pos;

// STATIC
    static ndShaderProgram program;

public:
    ndFrame();

    // Rendering
    void draw();

// STATIC
    static void init();
};

#endif

#ifdef FRAME_MACROS
#endif