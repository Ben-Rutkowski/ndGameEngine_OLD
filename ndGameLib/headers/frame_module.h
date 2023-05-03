#include "vao.h"
#include "shader.h"
#include "event_manager.h"

#ifndef FRAME_MODULE_H
#define FRAME_MODULE_H

// TEMPLATE
class FrameModule
{
protected:
    float x_pos, y_pos;
    float width, height;

    EventManager* event_manager;

    VAO vao;
    ndShaderProgram program;

public:
    FrameModule(float x_in, float y_in, float wdth_in, float hght_in);

};


// MENU BAR --------------------------------
#define MAX_OPTIONS    1
#define MAX_OPTION_LEN 16

class MenuBarModule : FrameModule
{
private:
    char option_list[MAX_OPTIONS * MAX_OPTION_LEN];
    int counter;

public:
    MenuBarModule(float x, float y, float wdth_in, float hght_in);
};

#endif

#ifdef FRAME_MODULE_MACROS
#endif