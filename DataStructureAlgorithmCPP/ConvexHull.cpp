#include "listAlgorithm.h"


#pragma comment  (lib,"User32.lib") 
#pragma comment  (lib,"Gdi32.lib") 

struct Point
{
	int _x;
	int _y;
	Point(int x,int y):_x(x),_y(y){};
	Point():_x(0),_y(0){};
	bool operator!=(Point pt)
	{
		return (_x!=pt._x) || (_y!=pt._y);
	};
};

ostream& operator<<(ostream& out, Point pt)
{
	out<<pt._x<<" "<<pt._y<<"\t";
	return out;
};

LinearList<Point>* createPoints(int number)
{
	ChainList<Point> *ptList = new ChainList<Point>;
	for(int i=0;i<number;i++)
	{
		int x = randomCreate(113);
		int y = randomCreate(107);
		Point *pt = new Point(x,y);
		ptList->insert(0,*pt);
	}
	return ptList;
}

int main2()
{
	LinearList<Point> *ptList = createPoints(20);
	cout<<*ptList<<endl;
	return 0;
}

void OnPaint(HWND hwnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd,&ps);
	CDC *dc = CDC::FromHandle(hdc);
	LinearList<Point> *ptList = createPoints(20);
	CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
//	dc->SelectObject(pBrush);
	for(int i=0;i<20;i++)
	{
		CPoint point(ptList->get(i)._x,ptList->get(i)._y);
		dc->SetPixel(point,RGB(255,0,0));
	}
	EndPaint(hwnd,&ps);
};

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR szCmdLine, int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("HelloWin");
    HWND         hwnd;
    MSG          msg;
    WNDCLASS     wndclass;

    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;

    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT("This program requires Windows NT!"),
            szAppName, MB_ICONERROR);
        return 0;
    }

    hwnd = CreateWindow(szAppName,                  // window class name
        TEXT("The Hello Program"), // window caption
        WS_OVERLAPPEDWINDOW,        // window style
        CW_USEDEFAULT,              // initial x position
        CW_USEDEFAULT,              // initial y position
        CW_USEDEFAULT,              // initial x size
        CW_USEDEFAULT,              // initial y size
        NULL,                       // parent window handle
        NULL,                       // window menu handle
        hInstance,                  // program instance handle
        NULL);                     // creation parameters

    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC         hdc;
    PAINTSTRUCT ps;
    RECT        rect;


    switch (message)
    {
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
	case WM_PAINT:
		OnPaint(hwnd);
		break;
    default:
        return DefWindowProc(hwnd, message, wParam, lParam);

    }

    return 0;
}

