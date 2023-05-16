#include "vec.h"

// vec4 --------------------------------
vec4::vec4() {}
vec4::vec4(float x_in, float y_in, float z_in, float w_in)
{
    vec[0] = x_in;    vec[1] = y_in;
    vec[2] = z_in;    vec[3] = w_in;
}

void vec4::set(int i, float value) { vec[i] = value; }
float vec4::x() { return vec[0]; }
float vec4::y() { return vec[1]; }
float vec4::z() { return vec[2]; }
float vec4::w() { return vec[3]; }
float vec4::operator[](int i) { return vec[i]; }

// Math --------------------------------
float vec4::dot(vec4 arg) { return vec[0]*arg[0] + vec[1]*arg[1] + vec[2]*arg[2] + vec[3]*arg[3]; }

// STATIC
vec4 vec4::basis(int i)
{
    switch (i)
    {
    case 0:  return vec4(1.0f, 0.0f, 0.0f, 0.0f); break;
    case 1:  return vec4(0.0f, 1.0f, 0.0f, 0.0f); break;
    case 2:  return vec4(0.0f, 0.0f, 1.0f, 0.0f); break;
    case 3:  return vec4(0.0f, 0.0f, 0.0f, 1.0f); break;
    default: return vec4(0.0f, 0.0f, 0.0f, 0.0f); break;
    }
}

// vec2 --------------------------------
vec2::vec2() {}
vec2::vec2(float x_in, float y_in) : x_val{ x_in }, y_val{ y_in } {}
float vec2::x() { return x_val; }
float vec2::y() { return y_val; }
float vec2::operator[](int i)
{
    switch (i)
    {
        case 0: return x_val; break;
        case 1: return y_val; break;
        default: return 0.0f; break;
    }
}

void vec2::screentToLetter(float ratio) { x_val = ratio*x_val; }