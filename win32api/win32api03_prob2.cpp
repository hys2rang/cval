#include <windows.h>
#include <TCHAR.H>
#include <stdlib.h>
#define SIZE 10
#define MS 10
int dir[8][2] = { {-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{-1,1},{0,-1} };
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam);
VOID CALLBACK TimeProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdLine, int nCmdShow)
{
	HWND     hwnd;
	MSG		 msg;
	WNDCLASS WndClass;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = _T("Window Class Name");
	RegisterClass(&WndClass);
	hwnd = CreateWindow(_T("Window Class Name"),
		_T("Window Title Name"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	static RECT rt;
	static POINT ptCircle = { 0 };//아직 창이 존재하지 않으므로 초기화 할 수 없다.
	static int select;
	static int dir_x, dir_y;
	PAINTSTRUCT ps;
	switch (iMsg)
	{
	case WM_CREATE:
	{
		srand(GetTickCount());
		GetClientRect(hwnd, &rt);
		ptCircle.x = rt.right / 2;
		ptCircle.y = rt.bottom / 2;
		select = rand() % 8;
		dir_x = dir[select][0];
		dir_y = dir[select][1];
		SetTimer(hwnd, select, 100, NULL);//handler, ID, interval, procedure
	}
	break;
	case WM_TIMER:
		if (ptCircle.x + SIZE > rt.right || ptCircle.x - SIZE < 0) {
			dir_x *= (-1);
		}
		else if (ptCircle.y + SIZE > rt.bottom || ptCircle.y - SIZE < 0) {
			dir_y *= (-1);
		}
		ptCircle.x += dir_x * MS;
		ptCircle.y += dir_y * MS;
		InvalidateRect(hwnd, NULL, TRUE);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		Ellipse(hdc, ptCircle.x-SIZE, ptCircle.y - SIZE, ptCircle.x + SIZE, ptCircle.y + SIZE);
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
