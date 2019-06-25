#include <windows.h>
#include <TCHAR.H>
#include <vector>
using namespace std;
struct Point {
	int x;
	int y;
};
void DrawString(HDC hdc, Point pt)
{
	TCHAR buf[500];
	wsprintf(buf, _T("x : %d y : %d"), pt.x, pt.y);
	TextOut(hdc, pt.x, pt.y, buf, lstrlen(buf));
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
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
	static vector<Point> ptList;
	HDC hdc;
	PAINTSTRUCT ps; //구조체 타입은 다 대문자
	TCHAR buf[500];
	Point pt;
	switch (iMsg)
	{
	case WM_CREATE:
		break;
	case WM_PAINT://invalid area 처리 => 다시그리기를 하고나서 valid area로 만들어줘야함
		hdc = BeginPaint(hwnd, &ps);
		for (vector<int>::size_type i = 0; i < ptList.size(); i++) {
			DrawString(hdc, ptList[i]);
		}
		EndPaint(hwnd, &ps);
		break;
	case WM_LBUTTONDOWN: //마우스의 왼쪽 버튼을 클릭했을 때 발생되는 메시지
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);
		ptList.push_back(pt);
		hdc = GetDC(hwnd);
		DrawString(hdc, pt);
		ReleaseDC(hwnd, hdc);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
