#pragma once
#include <stdbool.h>
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
typedef void(Create_Window_Func)(int w, int h);
typedef void (Main_Render_Func)();
typedef void (Main_Update_Func)();
typedef void (Main_Input_Func)();
typedef void (Init_Func)(); //This is so that things can be initialized when the window is created
typedef void (RenderLoop_func)();
typedef void (Destroy_Window_func)();
typedef void (OnRenderingFinished_func)();
typedef void (OnRenderingFailure_func)();
typedef enum WINDOW_TYPE
{
    NONE,
	GL,
	SDL,
	GDI,
	DIRECTX,
	LUA
}WINDOW_TYPE;
WINDOW_TYPE Current_window;
Main_Render_Func* render_func;
Main_Update_Func* update_func;
Main_Input_Func* input_func;
Main_Render_Func* debug_render_func;
Main_Update_Func* debug_update_func;

Init_Func* init_func;
//void CreateWindow(Create_Window_Func* create_window);
void __declspec(dllexport) RenderLoop(RenderLoop_func* renderloop);
//void DestroyWindow(Destroy_Window_func* destroywindow);
void __declspec(dllexport) OnRenderingFinished(OnRenderingFinished_func* onrenderingfinished);
void __declspec(dllexport) OnRenderingFailure(OnRenderingFailure_func* onrenderingfailure);
void __declspec(dllexport) SetMainRenderCallback(Main_Render_Func* main_render_func);
void __declspec(dllexport) SetMainUpdateCallback(Main_Update_Func* main_update_func);
void __declspec(dllexport) SetDebugRenderCallback(Main_Render_Func* main_debug_render_func);
void __declspec(dllexport) SetDebugUpdateCallback(Main_Update_Func* main_debug_update_func);
void __declspec(dllexport) SetMainInputCallback(Main_Input_Func* main_input_func);
void __declspec(dllexport) SetInitCallback(Init_Func* init_func_custom);
void Tick();
