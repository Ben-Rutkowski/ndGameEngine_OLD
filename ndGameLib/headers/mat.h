#include "vec.h"

#ifndef MAT_H
#define MAT_H

class mat4
{
private:
    float mat[4][4];

public:
    mat4();
    mat4(vec4, vec4, vec4, vec4);
    void   set(int i, int j, float value);
    void   setCol(int j, vec4 col);
    float* getPtr();
    float  get(int i, int j);
    vec4   getCol(int j);
    vec4   getRow(int i);

    // Math
    mat4 leftMult(mat4 right);

    // STATIC
    static mat4 iden();
    static mat4 screenToLetter(float ratio);
    static mat4 letterToClip(int width, int height, int pixsize, vec2 pos);
};

#endif

#ifdef MAT_MACROS
#endif