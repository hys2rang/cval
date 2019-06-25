#include <windows.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam); //시그니처 == 프로토타입, 프로시저 선언
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	char* lpszCmdLine, int nCmdShow)
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
	WndClass.lpszClassName = "Window Class Name";
	RegisterClass(&WndClass);
	hwnd = CreateWindow("Window Class Name",
		"Window Title Name",
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
	while (GetMessage(&msg, NULL, 0, 0)) //queue message를 가져오는 메시지
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg); //프로시저를 호출하는 작업
		//main thread는 계속 여기있다. message를 읽고 번역하고 메시지를 처리함 get -> translate -> dispatch
	}

	//이 반복문에서 처리하는 메시지는 queue message이다.
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,	//윈도우 프로시저 : 메시지를 처리하는 함수(프로시저)
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	int x = 100, y = 100;
	static int count = 0;
	switch (iMsg)
	{
	case WM_CREATE:
		break;
	case WM_MOUSEMOVE://topwindow(가장 위에 있는 윈도우(z좌표가 가장 큰 값을 갖고 있는 윈도우))
		//dc(device context) : 기본적인 그리기 정보는 설정이 되어있다. 그릴때는 무조건 필요함
		++count;
		{
			char buf[100];
			wsprintf(buf, "count:%d", count);
			SetWindowText(hwnd, buf);
		}
		x = LOWORD(lParam);
		x = HIWORD(lParam);
		hdc = GetDC(hwnd);
		Ellipse(hdc, x - 30, y - 30, x + 30, y + 30);//좌표지정하고 지름이 60인원을 그려달라
		ReleaseDC(hwnd, hdc);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
