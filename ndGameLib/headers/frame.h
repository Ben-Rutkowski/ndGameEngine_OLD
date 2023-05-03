#include "shader.h"
#include "vao.h"

#ifndef FRAME_H
#define FRAME_H

// TODO:
// Header: a array of words
// Popup box: a single window with a list of options
// In frame optiions: sliders, check-box, number fill-in, color selection,
//                    mode select, window/layer system
// Scroll wheel                    


class ndFrame
{
private:
    VAO vao;
    float width, height;
    float x_pos, y_pos;

    float        buffer_data[8];
    unsigned int element_data[6];

// STATIC
    static ndShaderProgram program;

public:
    void setDimensions(float x_pos, float y, float width, float height);
    void calculateBufferData();
    void loadBuffer();
    void drawBoarder();

public:
    ndFrame();
    void addTopBorder();

    // Rendering
    void draw();

    // Events
    void onStartFrame();

// STATIC
    static void init();

};

#endif

#ifdef FRAME_MACROS
#endif