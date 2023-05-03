#define FRAME_MODULE_MACROS
#include "frame_module.h"

// FrameModule
// Initialization --------------------------------
FrameModule::FrameModule(float x_in, float y_in, float wdth_in, float hght_in)
: x_pos{ x_in }, y_pos{ y_in }, width{ wdth_in }, height{ hght_in } {}

// MENU BAR
// Initialization --------------------------------
MenuBarModule::MenuBarModule(float x_in, float y_in, float wdth_in, float hght_in)
: FrameModule(x_in, y_in, wdth_in, hght_in) {}
