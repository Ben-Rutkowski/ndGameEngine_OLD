#version 330 core

layout (points) in;
layout (triangle_strip, max_vertices = 4) out;

uniform float a_size;
uniform mat4  g_view_mat;

in VS_OUT {
    vec4 dim;
    vec4 bear;
    vec2 tex;
} gs_in[];

out GS_OUT {
    vec2 tex;
} gs_out;

void main()
{
    const vec3 unit = vec3(1.0, -1.0, 0.0);
    vec4 position;

    position    = gs_in[0].dim*unit.zyzz + gs_in[0].bear + gl_in[0].gl_Position;
    gl_Position = g_view_mat*position;
    gs_out.tex  = gs_in[0].tex;
    EmitVertex();

    position    = gs_in[0].dim*unit.xyzz + gs_in[0].bear + gl_in[0].gl_Position;
    gl_Position = g_view_mat*position;
    gs_out.tex  = gs_in[0].dim.xy*unit.xz + gs_in[0].tex;
    EmitVertex();

    position    = gs_in[0].bear + gl_in[0].gl_Position;
    gl_Position = g_view_mat*position;
    gs_out.tex  = gs_in[0].dim.xy*unit.zx + gs_in[0].tex;
    EmitVertex();

    position    = gs_in[0].dim*unit.xzzz + gs_in[0].bear + gl_in[0].gl_Position;
    gl_Position = g_view_mat*position;
    gs_out.tex  = gs_in[0].dim.xy*unit.xx + gs_in[0].tex;
    EmitVertex();

    EndPrimitive();
}

// #version 330 core

// layout (points) in;
// layout (triangle_strip, max_vertices = 4) out;

// uniform float a_size;
// uniform mat4  g_view_mat;

// in VS_OUT {
//     vec2 dim;
//     vec2 bear;
//     vec2 tex;
// } gs_in[];

// out GS_OUT {
//     vec2 tex;
// } gs_out;

// void main()
// {
//     const vec3 unit = vec3(1.0, -1.0, 0.0);

//     vec4 dim_s  = a_size*vec4(gs_in[0].dim, 0.0, 0.0);
//     vec4 bear_s = a_size*vec4(gs_in[0].bear, 0.0, 0.0);
//     vec4 position;

//     position    = dim_s*unit.zyzz + bear_s + gl_in[0].gl_Position;
//     // gl_Position = g_view_mat*position;
//     position = g_view_mat*position;
//     gl_Position = 2*position - vec4(2.0, 2.0, 0.0, 0.0);
//     gs_out.tex  = gs_in[0].tex;
//     EmitVertex();

//     position    = dim_s*unit.xyzz + bear_s + gl_in[0].gl_Position;
//     // gl_Position = g_view_mat*position;
//     position = g_view_mat*position;
//     gl_Position = 2*position - vec4(2.0, 2.0, 0.0, 0.0);
//     gs_out.tex  = gs_in[0].dim*unit.xz + gs_in[0].tex;
//     EmitVertex();

//     position    = bear_s + gl_in[0].gl_Position;
//     // gl_Position = g_view_mat*position;
//     position = g_view_mat*position;
//     gl_Position = 2*position - vec4(2.0, 2.0, 0.0, 0.0);
//     gs_out.tex  = gs_in[0].dim*unit.zx + gs_in[0].tex;
//     EmitVertex();

//     position    = dim_s*unit.xzzz + bear_s + gl_in[0].gl_Position;
//     // gl_Position = g_view_mat*position;
//     position = g_view_mat*position;
//     gl_Position = 2*position - vec4(2.0, 2.0, 0.0, 0.0);
//     gs_out.tex  = gs_in[0].dim*unit.xx + gs_in[0].tex;
//     EmitVertex();

//     EndPrimitive();
// }