#define MAT_MACROS
#include "mat.h"

mat4::mat4() {}
mat4::mat4(vec4 x_in, vec4 y_in, vec4 z_in, vec4 w_in)
{
    setCol(0, x_in);
    setCol(1, y_in);
    setCol(2, z_in);
    setCol(3, w_in);
}

void mat4::set(int i, int j, float value) { mat[i][j] = value; }

void mat4::setCol(int j, vec4 col)
{
    for (int i=0; i<4; i++)
        mat[i][j] = col[i];
}

float mat4::get(int i, int j) { return mat[i][j]; }

vec4 mat4::getCol(int j) { return vec4(get(0, j), get(1, j), get(2, j), get(3, j)); }
vec4 mat4::getRow(int i) { return vec4(get(i, 0), get(i, 1), get(i, 2), get(i, 3)); }

// Math --------------------------------
mat4 mat4::leftMult(mat4 right)
{
    mat4 product;

    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            product.set(i, j, getRow(i).dot(right.getCol(j))); 
    
    return product;
}

// STATIC --------------------------------
mat4 mat4::iden() { return mat4(vec4::basis(0), vec4::basis(1), vec4::basis(2), vec4::basis(3)); }

mat4 mat4::screenToLetter(int width, int height)
{
    float ratio  = (float)width/(float)height;
    mat4  output = mat4::iden();

    output.set(0, 0, ratio);
    return output;
}

mat4 mat4::letterToClip(int width, int height)
{
    float ratio  = (float)height/(float)width;
    mat4  output = mat4::iden();
    
    output.set(0, 0, 0.5f*ratio);
    output.set(1, 1, 0.5f);
    output.set(0, 3, 1.0f);
    output.set(1, 3, 1.0f);
    return output;
}

