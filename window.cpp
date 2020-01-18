#include "window.h"
#include <windows.h>
#include <tchar.h>
using namespace std;
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
char t;
bool lb,mb,rb;
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            return 0;
        case WM_KEYDOWN:
            t=wParam;
            return 0;
        case WM_LBUTTONDOWN:
            lb=true;
           return 0;
        case WM_MBUTTONDOWN:
            mb=true;
            return 0;
        case WM_RBUTTONDOWN:
            rb=true;
            return 0;
        case WM_LBUTTONUP:
            lb=false;
            return 0;
        case WM_MBUTTONUP:
            mb=false;
            return 0;
        case WM_RBUTTONUP:
            rb=false;
            return 0;
        case WM_NULL:
            return 0;

        default:
            break;
    }

    return DefWindowProc (hwnd, message, wParam, lParam);
}

window::window()
{
    wincl.hInstance = GetModuleHandle(NULL) ;
    wincl.lpszClassName = _T("WindowsApp");
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH) COLOR_3DDKSHADOW;
    RegisterClassEx (&wincl);
    hwnd = CreateWindowEx (
           0,
           _T("WindowsApp"),         /* Classname */
           _T("NewWindow"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           375,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           GetModuleHandle(NULL),       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );
           hdc=GetDC(hwnd);
    bitm=CreateCompatibleBitmap(hdc,544,375);
SelectObject(hdc,bitm);
height=544;
width=255;
}

window::window(char* title,int _width,int _height)
{
    wincl.hInstance = GetModuleHandle(NULL) ;
    wincl.lpszClassName = _T("WindowsApp");
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    RegisterClassEx (&wincl);
    hwnd = CreateWindowEx (
           0,
           _T("WindowsApp"),         /* Classname */
           _T(title),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           _width,                 /* The programs width */
           _height,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           GetModuleHandle(NULL),       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );
           hdc=GetDC(hwnd);


bitm=CreateCompatibleBitmap(hdc,width,height);
SelectObject(hdc,bitm);
height=_height;
width=_width;
}

void window::show(){
    ShowWindow (hwnd, 10);

}
bool window::update(){


    if (PeekMessage(&messages, NULL, 0, 0, PM_REMOVE))
		{
			// test if this is a quit msg
			if (messages.message == WM_QUIT)
				return false;

			// translate any accelerator keys
			TranslateMessage(&messages);

			// send the message to the window proc
			DispatchMessage(&messages);
			return true;
		}
		return true;

}
window::~window(){
    //dtor
}



void window::drawPixel(int x,int y,color col){
    SetPixel(hdc,x,y,col);
}
void window::drawLine(int x1,int y1,int x2,int y2,int linewidth,color col){
    setPen(linewidth,col);
    MoveToEx(hdc,x1,y1,NULL);
    LineTo(hdc,x2,y2);
}
void window::setPen(int w,color col){
    pen=CreatePen(PS_SOLID,w,col);
    SelectObject(hdc,pen);
}
void window::setBrush(color col){
    brush=CreateSolidBrush(col);
    SelectObject(hdc,brush);
}

void window::drawEllipse(int x1,int y1,int x2,int y2,int linewidth,color line,color fill){
    setPen(linewidth,line);
    setBrush(fill);
    Ellipse(hdc,x1,y1,x2,y2);
}

void window::drawRectangle(int x1,int y1,int x2,int y2,int linewidth,color line,color fill){
    setPen(linewidth,line);
    setBrush(fill);
    Rectangle(hdc,x1,y1,x2,y2);
}

void window::drawRoundRect(int x1,int y1,int x2,int y2,int linewidth,int arcSize,color line,color fill){
    setPen(linewidth,line);
    setBrush(fill);
    RoundRect(hdc,x1,y1,x2,y2,arcSize,arcSize);

}


void window::drawPolygon(point *pointss,int num,int linewidth,color line,color fill){
    setPen(linewidth,line);
    setBrush(fill);
    Polygon(hdc,pointss,num);
}

void window::drawPolyline(point *points,int num,int linewidth,color line){
    setPen(linewidth,line);
    Polyline(hdc,points,num);
}

void window::drawText(int x,int y,const char *str,color col){
    SetTextColor(hdc,col);
    TextOut(hdc,x,y,str,strlen(str));
}

void window::drawText(int x,int y,string str,color col){
    SetTextColor(hdc,col);
    TextOut(hdc,x,y,str.c_str(),str.length());
}

point XY(int x,int y){
    point t;
    t.x=x;
    t.y=y;
    return t;
}

char window::getKey(){
    key=t;
    return key;
}

bool window::leftMouseDown(){
    return lb;
}
bool window::mediumMouseDown(){
    return mb;
}
bool window::rightMouseDown(){
    return rb;
}

void window::clear(){
	RECT rect;

	SetRect(&rect, 0, 0, width, height);

	brush = CreateSolidBrush(WHITE);
	FillRect(hdc, &rect, brush);

drawRectangle(0,0,width,height,1,WHITE,WHITE);
}

void window::erase(int x1,int y1,int x2,int y2){
	RECT rect;
	SetRect(&rect, x1, x2, y1, y2);
	brush = CreateSolidBrush(WHITE);
	FillRect(hdc, &rect, brush);
}

void window::fillRect(int x1,int y1,int x2,int y2,color col){
    RECT rect;
	SetRect(&rect, x1, x2, y1, y2);
	brush = CreateSolidBrush(col);
	FillRect(hdc, &rect, brush);
}

void window::drawBitmap(int x,int y,char* address){
    HDC temp;
    temp  = CreateCompatibleDC(hdc);
    HBITMAP hbmp;
    BITMAP bmp;
    hbmp = (HBITMAP)LoadImage(NULL, address, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE|LR_CREATEDIBSECTION);
    GetObject(hbmp, sizeof(BITMAP), &bmp);
    SelectObject(temp, hbmp);
    BitBlt(hdc, x, y, bmp.bmWidth, bmp.bmHeight, temp, 0, 0, SRCCOPY);
}

color window::getPixelColor(int x,int y){
    return GetPixel(hdc,x,y);
}
