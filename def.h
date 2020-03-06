
#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED
#include<windows.h>
#define screenWidth GetSystemMetrics(SM_CXFULLSCREEN);
#define screenHeight GetSystemMetrics(SM_CYFULLSCREEN);
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define desktopHwnd HWND_DESKTOP
#define RED RGB(255,0,0)
#define GREEN RGB(0,255,0)
#define BLUE RGB(0,0,255)
#define YELLOW RGB(255,255,0)
#define PURPLE RGB(255,0,255)
#define BLUE RGB(0,0,255)
#define MINTGREEN RGB(0,255,255)
#define WHITE RGB(255,255,255)
#define BLACK RGB(0,0,0)
typedef COLORREF color;
typedef POINT point;



#endif // DEF_H_INCLUDED
