#ifndef VEC_H
#define VEC_H

class vec2
{
private:
    float x_val, y_val;

public:
    vec2(float x_in, float y_in);
    vec2();
    float x();
    float y();
};

#endif