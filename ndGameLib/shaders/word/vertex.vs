#version 330 core

layout (location = 0) in vec2  v_dim;
layout (location = 1) in vec2  v_bear;
layout (location = 2) in vec2  v_tex;
layout (location = 3) in float v_index;

uniform float v_adv;
uniform vec2  v_origin;
uniform float a_size;

out VS_OUT {
    vec2 dim;
    vec2 bear;
    vec2 tex;
} vs_out;

void main()
{
    vec2 root   = v_origin + vec2(v_adv*v_index, 0.0);
    gl_Position = vec4(a_size*root, 0.0, 1.0);

    vs_out.dim  = v_dim;
    vs_out.bear = v_bear;
    vs_out.tex  = v_tex;
}