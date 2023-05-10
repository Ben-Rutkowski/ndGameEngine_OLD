#include "vec.h"

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

// vec4 --------------------------------
vec4::vec4() {}
vec4::vec4(float x_in, float y_in, float z_in, float w_in)
: x_val{ x_in },
  y_val{ y_in },
  z_val{ z_in },
  w_val{ w_in } {}

void vec4::set(int i, float value)
{
    switch (i)
    {
    case 0:  x_val = value; break;
    case 1:  y_val = value; break;
    case 2:  z_val = value; break;
    case 3:  w_val = value; break;
    default: break;
    }
}

float vec4::x() { return x_val; }
float vec4::y() { return y_val; }
float vec4::z() { return z_val; }
float vec4::w() { return w_val; }
float vec4::operator[](int i)
{
    switch (i)
    {
        case 0: return x_val; break;
        case 1: return y_val; break;
        case 2: return z_val; break;
        case 3: return w_val; break;
        default: return 0.0f; break;
    }
}

// Math --------------------------------
float vec4::dot(vec4 arg)
{
    return x_val*arg.x() + y_val*arg.y() + z_val*arg.z() + w_val*arg.w();
}

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