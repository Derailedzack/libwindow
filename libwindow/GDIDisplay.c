#include "GDIDisplay.h"
 #ifdef defined(_WIN32) || defined(WIN32)
void GDI_DrawAll()
{
}

LRESULT CALLBACK GDI_Windowcallback(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) // @suppress("No return")
{
	PAINTSTRUCT ps;
	RECT* text_rect = malloc(sizeof(RECT));
	text_rect->bottom = 0;
	text_rect->top = 0;
	text_rect->right = 0;
	text_rect->left = 0;
	HDC hdc = GetDC(hwnd);
	switch (msg)
	{

	case WM_CREATE:

		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd,&ps);
		//SetRect(text_rect,0,0,0,0);
		SelectObject(hdc,LTGRAY_BRUSH);
		//Rectangle(hdc,text_rect->left,text_rect->top,text_rect->right,text_rect->bottom);
		//FillRect(hdc,text_rect,(HBRUSH)RGB(0,255,255));
DrawText(hdc,"Test!",strlen("Test!")-1,text_rect,DT_CENTER);
		EndPaint(hwnd,&ps);
		break;
	case WM_COMMAND:
		break;
	default:
		return DefWindowProc(hwnd,msg,wParam,lParam);
	}
}

void GDI_CreateWin(int w, int h)
{
	WNDCLASSEX wnd_class;
	wnd_class.cbSize = sizeof(wnd_class);
	wnd_class.style = CS_HREDRAW | CS_VREDRAW;
	wnd_class.lpfnWndProc = GDI_Windowcallback;
	wnd_class.hInstance = GetModuleHandle(NULL);
	wnd_class.cbClsExtra = 0;
	wnd_class.cbWndExtra = 0;
	wnd_class.hIcon = NULL;
	wnd_class.hCursor = NULL;
	wnd_class.hbrBackground = GetStockObject(DKGRAY_BRUSH);
	wnd_class.lpszMenuName = NULL;
	wnd_class.lpszClassName = "GDIWINDOW";
	wnd_class.hIconSm = NULL;
	if (RegisterClassExA(&wnd_class) == 0) {
		MessageBox(NULL, strerror(GetLastError()),"FATAL ERROR" ,MB_ICONERROR);
	}
	hwnd = CreateWindow("GDIWINDOW", "Test", WS_OVERLAPPEDWINDOW | WS_VISIBLE , CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, GetModuleHandle(NULL), NULL);
}


void GDI_EVENT_LOOP()
{
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	UpdateWindow(hwnd);
}
void GDI_ShowWin() {
	//ShowWindow(hwnd, 5);

}
#endif
