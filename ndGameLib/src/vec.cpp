#include "vec.h"

// Initialization
vec2::vec2(float x_in, float y_in) : x_val{ x_in }, y_val{ y_in } {}
vec2::vec2()                       : x_val{ 0.0f }, y_val{ 0.0f } {}
float vec2::x() { return x_val; }
float vec2::y() { return y_val; } 