#include "vao.h"
#include "shader.h"
#include "vec.h"

#ifndef WORD_H
#define WORD_H

// LETTER
struct Letter
{
    char letter;
    vec2 dimensions;
    vec2 bearings;
    vec2 tex_coords;

    Letter();
    void setLetter(char let_in);
};

class Word
{
private:
    Letter* word;
    int     len;
    float   advance;

    VAO              buffer;
    ndShaderProgram* program;
    float*           render_data;

public:
    Word(const char* word_in);
    ~Word();

    // Rendering 
    void loadBuffer();
    void draw(vec2 position, float size);
};

#endif

#ifdef WORD_MACROS
#endif