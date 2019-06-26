#include <windows.h>
#include <TCHAR.H>
#include <vector>
#define SIZE 3
using namespace std;
class POLYGON {
	vector<POINT> ptList;
public:
	void Add(const POINT& pt) {
		ptList.push_back(pt);
	}
	bool Empty()const {
		return ptList.empty();
	}
	const POINT* operator&() {
		return &ptList[0];
	}
	const POINT operator[](int i){
		return ptList[i];
	}
	int Points()const {
		return (int)ptList.size();
	}
	void Clear(){
		ptList.clear();
	}
	void Pop() {
		ptList.pop_back();
	}
	void Draw(HDC hdc) {
		Polygon(hdc, &*this, (int)Points());
	}
};
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
	static POLYGON polygon;
	static vector<POLYGON> polyList;
	static RECT rt;
	HDC hdc;
	PAINTSTRUCT ps;
	POINT pt;

	switch (iMsg)
	{
	case WM_CREATE:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		for (vector<POLYGON>::size_type i = 0; i < polyList.size(); i++) {
			polyList[i].Draw(hdc);
		}
		EndPaint(hwnd, &ps);
		break;
	case WM_LBUTTONDOWN:
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);

		hdc = GetDC(hwnd);
		polygon.Add(pt);

		rt = { polygon[0].x - SIZE + 1, polygon[0].y - SIZE + 1, polygon[0].x + SIZE + 1, polygon[0].y + SIZE + 1 };
		if (polygon.Points() > 1 && PtInRect(&rt, pt))
		{
			polygon.Pop();
			polyList.push_back(polygon);
			polygon.Clear();
			InvalidateRect(hwnd, NULL, FALSE);
			break;
		}
		Ellipse(hdc, pt.x - SIZE, pt.y - SIZE, pt.x + SIZE, pt.y + SIZE);
		ReleaseDC(hwnd, hdc);
		break;
	case WM_RBUTTONDOWN:
		polyList.push_back(polygon);
		polygon.Clear();
		InvalidateRect(hwnd, NULL, FALSE);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}
