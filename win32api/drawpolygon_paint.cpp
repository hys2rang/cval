#include <windows.h>
#include <TCHAR.H>
#include <vector>
#include <queue>
#define SIZE 3
using namespace std;

void DrawCircle(HDC hdc, POINT pt)
{
	Ellipse(hdc, pt.x - SIZE, pt.y - SIZE, pt.x + SIZE, pt.y + SIZE);
}
void DrawLine(HDC hdc, vector<POINT> ptList, int startpt)
{
	Polygon(hdc, &ptList[startpt], ptList.size() - startpt);
}
void DrawLine(HDC hdc, vector<POINT> ptList, int startpt,int endpt)
{
	Polygon(hdc, &ptList[startpt], endpt-startpt);
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
	static vector<POINT> ptList;
	static vector<int> lastpt;
	static int cnt = 0;
	HDC hdc;
	PAINTSTRUCT ps; //구조체 타입은 다 대문자
	POINT pt;
	switch (iMsg)
	{
	case WM_CREATE:
		break;
	case WM_PAINT://invalid area 처리 => 다시그리기를 하고나서 valid area로 만들어줘야함 ===> Queue message
		//그리기만 해야한다. 데이터 조작x
		hdc = BeginPaint(hwnd, &ps); //==>무효한 영역을 유효화
		
		for (vector<int>::size_type i = 0, j = 0; i < ptList.size(); i++) {
			pt = ptList[i];
			DrawCircle(hdc, pt);
			if (!lastpt.empty() && (lastpt.size()>j+1) && (i+1 == (lastpt[j+1]))) {
				DrawLine(hdc, ptList, lastpt[j], lastpt[j+1]);
				lastpt[j++];
			}
		}
		EndPaint(hwnd, &ps);
		break;
	case WM_LBUTTONDOWN: //마우스의 왼쪽 버튼을 클릭했을 때 발생되는 메시지
		//데이터를 획득하는 부분
		hdc = GetDC(hwnd);
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);
		DrawCircle(hdc, pt);
		ptList.push_back(pt);
		break;
	case WM_RBUTTONDOWN:
		hdc = GetDC(hwnd);
		DrawLine(hdc, ptList, cnt);
		cnt = ptList.size();
		if (lastpt.empty()) {
			lastpt.push_back(0);//마지막 점의 위치
		}
		lastpt.push_back(ptList.size());
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
