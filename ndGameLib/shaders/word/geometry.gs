#version 330 core

layout (points) in;
layout (triangle_strip, max_vertices = 4) out;

uniform float a_size;

in VS_OUT {
    vec2 dim;
    vec2 bear;
    vec2 tex;
} gs_in[];

out GS_OUT {
    vec2 tex;
} gs_out;

void main()
{
    const vec3 unit = vec3(1.0, -1.0, 0.0);

    vec4 dim_s  = a_size*vec4(gs_in[0].dim, 0.0, 0.0);
    vec4 bear_s = a_size*vec4(gs_in[0].bear, 0.0, 0.0);

    gl_Position = dim_s*unit.zyzz + bear_s + gl_in[0].gl_Position;
    gs_out.tex  = gs_in[0].tex;
    EmitVertex();

    gl_Position = dim_s*unit.xyzz + bear_s + gl_in[0].gl_Position;
    gs_out.tex  = gs_in[0].dim*unit.xz + gs_in[0].tex;
    EmitVertex();

    gl_Position = bear_s + gl_in[0].gl_Position;
    gs_out.tex  = gs_in[0].dim*unit.zx + gs_in[0].tex;
    EmitVertex();

    gl_Position = dim_s*unit.xzzz + bear_s + gl_in[0].gl_Position;
    gs_out.tex  = gs_in[0].dim*unit.xx + gs_in[0].tex;
    EmitVertex();

    EndPrimitive();
}