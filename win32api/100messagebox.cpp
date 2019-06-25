#include <windows.h>
#include <TCHAR.H>
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam); //시그니처를 통한 프로시저 선언
//hwnd : window handle
//UNIT : message number(integer)
//wparam : word(2byte) -> (4byte) 부가적인 번호
//Lparam : long(4byte) 부가적인 정보
//wparam+Lparam : 8byte의 부가적인 정보
//LRESULT : L Result형(반환타입)
//CALLBACK : os가 호출한다
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdLine, int nCmdShow)
	//WINAPI :
	//HINSTANCE : Handle instance(process) -> program의 instance
	//hInstance : 내 프로세스의 인스턴스
	//hprevfinstance : 부모 프로세스의 인스턴스
	//lpszCmdLine : argv
	//nCmdShow : showWindow에 사용되는 정수값(최소화, 최대화, default) ==> 외부에서 설정한 형태로 띄우겠다.
{
	HWND     hwnd;	//윈도우 핸들(핸들앞에는 보통 H가 있다) 4byte 정수
	MSG		 msg;	//struct 6가지 정보를 보관한다.
	WNDCLASS WndClass;	//
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;	//이 윈도우에서 발생하는 것은 WndProc에 전달된다. lp = long형 포인터 long ptr function WndProc ==> 함수의 주소를 담은 포인터
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = _T("Window Class Name");	//Window Class의 이름
	RegisterClass(&WndClass);

	hwnd = CreateWindow(_T("Window Class Name"),//Window Class
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

	ShowWindow(hwnd, nCmdShow);//메모리상에 생성된 것을 화면으로 보여준다. (큐에 보관)
	UpdateWindow(hwnd);//지금당장 프로시저에 전달(큐를 경유하지 않고)

	while (GetMessage(&msg, NULL, 0, 0))
	{
		//TranslateMessage(&msg); //키보드와 관련
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam)

	//message를 dispatch할 때
{
	static int cnt = 0;
	int create = 0; //stack 변수여서 유지되지 않는다.
	switch (iMsg)
	{
	case WM_CREATE:
		create = 1; //윈도우 생성시 초기화 하는 지점
		break;
	case WM_MOUSEMOVE:
	{
		cnt++;
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		TCHAR charr[100];
		wsprintf(charr, "x : %d y : %d", x, y);
		if (cnt == 100) {
			MessageBox(hwnd, charr, "100번째!", MB_OK);
		}
		HDC hdc = GetDC(hwnd);
		Rectangle(hdc, x - 20, y - 20, x + 20, y + 20);
		ReleaseDC(hwnd, hdc);
	}
		break;
	case WM_DESTROY:
		PostQuitMessage(100);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
