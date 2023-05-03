#define FRAME_MACROS
#include "frame.h"
#include "shader_paths.h"

ndFrame::ndFrame() : x_pos{ 0.0f }, y_pos{ 0.0f }, width{ 1.0f }, height{ 0.5f }
{
    calculateBufferData();
}

ndShaderProgram ndFrame::program = ndShaderProgram();

// Rendering --------------------------------
void ndFrame::draw()
{
    drawBoarder();
}


// STATIC --------------------------------
void ndFrame::init()
{
    program.attachShader(FRAME_VERTEX, ShaderType::VERTEX);
    program.attachShader(FRAME_FRAGMENT, ShaderType::FRAGMENT);
    program.compileProgram();
    // program.printLog();
}

// Private --------------------------------
void ndFrame::drawBoarder()
{
    vao.drawTriangles(2, program);
}

void ndFrame::calculateBufferData()
{
    buffer_data[0] = x_pos;
    buffer_data[1] = y_pos;

    buffer_data[2] = x_pos + width;
    buffer_data[3] = y_pos;

    buffer_data[4] = x_pos + width;
    buffer_data[5] = y_pos + height;

    buffer_data[6] = x_pos;
    buffer_data[7] = y_pos + height;

    element_data[0] = 0;
    element_data[1] = 1;
    element_data[2] = 2;
    element_data[3] = 2;
    element_data[4] = 3;
    element_data[5] = 0;

    loadBuffer();
}

void ndFrame::loadBuffer()
{
    vao.loadArrayStatic(8 * sizeof(float), buffer_data);
    vao.loadElementStatic(6 * sizeof(unsigned int), element_data);
    vao.addAttribPointerf(2, 0);
}