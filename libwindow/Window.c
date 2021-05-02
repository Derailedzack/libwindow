#include "Window.h"
/*SetCurrentWindowType and GetCurrentWindowType no longer have a function prototype in the header*/
//void SetCurrentWindowType()
//{
//}
//WINDOW_TYPE GetCurrentWindowType(WINDOW_TYPE win_type)
//{

	//return false;
//}
//void CreateWindow(Create_Window_Func* create_window)
//{
//	(create_window)(WINDOW_WIDTH,WINDOW_HEIGHT);
//}

void RenderLoop(RenderLoop_func* renderloop)
{
	(renderloop)();
}

//void DestroyWindow(Destroy_Window_func* destroywindow)
//{
//	(destroywindow)();
//}

void OnRenderingFinished(OnRenderingFinished_func* onrenderingfinished)
{
	(onrenderingfinished)();
}

void OnRenderingFailure(OnRenderingFailure_func* onrenderingfailure)
{
	(onrenderingfailure)();
}

void Tick()
{
}
void  __declspec(dllexport) SetMainRenderCallback(Main_Render_Func* main_render_func) {
	render_func = main_render_func;
}
void  __declspec(dllexport) SetMainUpdateCallback(Main_Update_Func* main_update_func) {
	update_func = main_update_func;
}
void  __declspec(dllexport) SetInitCallback(Init_Func* init_func_custom) {
	init_func = init_func_custom;
}
void  __declspec(dllexport) SetDebugRenderCallback(Main_Render_Func* main_debug_render_func) {
	debug_render_func = main_debug_render_func;
}
void  __declspec(dllexport) SetDebugUpdateCallback(Main_Update_Func* main_debug_update_func) {
	debug_update_func = main_debug_update_func;
}
void  __declspec(dllexport) SetMainInputCallback(Main_Input_Func* main_input_func) {
	input_func = main_input_func;
}