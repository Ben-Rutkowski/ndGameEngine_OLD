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
    float operator[](int);
};

class vec4
{
private:
    float x_val, y_val, z_val, w_val;

public:
    vec4();
    vec4(float x_in, float y_in, float z_in, float w_in);
    void set(int i, float value);
    float x();
    float y();
    float z();
    float w();
    float operator[](int);

    // Math
    float dot(vec4 arg);

    // STATIC
    static vec4 basis(int i);
};

#endif