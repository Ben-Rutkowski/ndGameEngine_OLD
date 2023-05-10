#include "vec.h"

#ifndef MAT_H
#define MAT_H

class mat4
{
private:
    vec4 x_col;
    vec4 y_col;
    vec4 z_col;
    vec4 w_col;

public:
    mat4();
    mat4(vec4, vec4, vec4, vec4);
    void  set(int i, int j, float value);
    void  setCol(int j, vec4 col);
    float get(int i, int j);
    vec4  getCol(int j);
    vec4  getRow(int i);

    // Math
    mat4 leftMult(mat4 right);

    // STATIC
    static mat4 iden();
    static mat4 screenToLetter(int width, int height);
    static mat4 letterToClip(int width, int height);
};

#endif

#ifdef MAT_MACROS
#endif