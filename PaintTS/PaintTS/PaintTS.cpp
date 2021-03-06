// PaintTS.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "PaintTS.h"
#include "stdio.h"

HINSTANCE g_hInstance = 0;  
HANDLE hOutput;
void DrawRect()
{

}

//窗口处理函数  
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)  
{  
	
	switch (uMsg)  
	{  
	case WM_DESTROY:  
		PostQuitMessage(0);//可以使GetMessage返回0  
		break;
	case  WM_PAINT:
		{
			PAINTSTRUCT pt;
			HDC hdc;
			hdc=BeginPaint(hWnd,&pt);
			Rectangle(hdc,0,0,100,100);
			EndPaint(hWnd,&pt);
		}
	case WM_LBUTTONDOWN:
		{
			//InvalidateRect(hWnd,NULL,true);
		}
		break;
	default:  
		break;  
	}  
	return DefWindowProc(hWnd, uMsg, wParam, lParam);  
}  

//注册窗口类  
BOOL Register(LPSTR lpClassName, WNDPROC wndProc)  
{  
	WNDCLASSEX wce = { 0 };  
	wce.cbSize = sizeof(wce);  
	wce.cbClsExtra = 0;  
	wce.cbWndExtra = 0;  
	wce.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);  
	wce.hCursor = NULL;  
	wce.hIcon = NULL;  
	wce.hIconSm = NULL;  
	wce.hInstance = g_hInstance;  
	wce.lpfnWndProc = wndProc;  
	wce.lpszClassName = lpClassName;  
	wce.lpszMenuName = NULL;  
	wce.style = CS_HREDRAW | CS_VREDRAW;  
	ATOM nAtom = RegisterClassEx(&wce);  
	if (nAtom == 0)  
		return FALSE;  
	return true;  

}  
//创建主窗口  
HWND CreateMain(LPSTR lpClassName, LPSTR lpWndName)  
{  
	HWND hWnd = CreateWindowEx(0, lpClassName, lpWndName,  
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, g_hInstance, NULL);  
	return hWnd;  
}  
//显示窗口  
void Display(HWND hWnd)  
{  
	ShowWindow(hWnd, SW_SHOW);  
	UpdateWindow(hWnd);  
}  
//消息循环  
void Message()  
{  
	MSG nMsg = { 0 };  
	while (GetMessage(&nMsg, NULL, 0, 0))  
	{  
		TranslateMessage(&nMsg);  
		DispatchMessage(&nMsg);  
	}  
}  
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,  
	_In_opt_ HINSTANCE hPrevInstance,  
	_In_ LPWSTR    lpCmdLine,  
	_In_ int       nCmdShow)  
{  
	AllocConsole();
	hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	g_hInstance = hInstance;  
	BOOL nRet = Register("Main", WndProc);  
	if (!nRet)  
	{  
		MessageBox(NULL, "注册失败", "Infor", MB_OK);  
		return 0;  
	}  
	HWND hWnd = CreateMain("Main", "window");  
	Display(hWnd);  
	Message();  
	return 0;  
}  