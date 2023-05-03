#version 330 core

layout (location = 0) in vec2 pos_v;

void main()
{
    gl_Position = vec4(pos_v, 1.0, 1.0);
}