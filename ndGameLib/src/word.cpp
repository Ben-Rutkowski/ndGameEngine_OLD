#define WORD_MACROS
#include "word.h" 
#include "compiled_shaders.h"

// Letter
Letter::Letter() : letter{ '\0' } {}
void Letter::setLetter(char let_in)
{
    letter = let_in;

    float height = 0.75f;
    float width  = 0.75f;

    float x_bearing = (1.0f - width) / 2.0f;
    float y_bearing = height;

    float u = 0.0f;
    float v = 0.0f;

    dimensions = vec2(width, height);
    bearings   = vec2(x_bearing, y_bearing);
    tex_coords = vec2(u, v);
}

// Word
Word::Word(const char* word_in) : len{ 0 }, advance{ 1.0f }
{
    // Allocate memory for the letters and the render_data
    while (word_in[len]!='\0') { len++; }
    word        = new Letter[len];
    render_data = new float[len * 7];

    // Set Letters
    for (int i=0; i<len; i++)  { word[i].setLetter(word_in[i]); }

    // Set render_data
    for (int i=0; i<len; i++)
    {
        render_data[i*7 + 0] = word[i].dimensions.x(); // width
        render_data[i*7 + 1] = word[i].dimensions.y(); // height
        render_data[i*7 + 2] = word[i].bearings.x();   // x_bearing
        render_data[i*7 + 3] = word[i].bearings.y();   // y_bearing
        render_data[i*7 + 4] = word[i].tex_coords.x(); // tex_u
        render_data[i*7 + 5] = word[i].tex_coords.y(); // tex_v
        render_data[i*7 + 6] = (float)i;               // i-th letter
    }

    // Get shader program
    program = ShaderArray::getWordProgram();
}

Word::~Word() { delete(word); delete(render_data); }

// Rendering 
void Word::loadBuffer()
{
    int data_width = sizeof(float) * 7;
    buffer.loadArrayStatic(data_width*len, render_data);
    buffer.addAttribPointerf(0, 2, data_width, 0); // vec2  width,     height
    buffer.addAttribPointerf(1, 2, data_width, 2); // vec2  x_bearing, y_bearing
    buffer.addAttribPointerf(2, 2, data_width, 4); // vec2  tex_u,     tex_v
    buffer.addAttribPointerf(3, 1, data_width, 6); // float index
}

void Word::draw(vec2 position, float size)
{
    program->use();
    program->uniform1f(advance, "v_adv");
    program->uniform2f(position, "v_origin");
    program->uniform1f(size, "a_size");

    buffer.drawPoints(len, program);
}
