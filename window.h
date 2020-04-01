#ifndef WINDOW_H
#define WINDOW_H
#include<windows.h>
#include<string>
#include "def.h"
using namespace std;
class window
{
    public:
        window();
        void drawPixel(int x,int y,color col);
        window(const char* _title,int width,int height);
        window(const char* _title,int _width,int _height,int x,int y,HWND father);
        bool update();
        virtual ~window();
        void show();
        bool isQuiting();
        void setText(color col);
        void drawLine(int x1,int y1,int x2,int y2);
        void drawEllipse(int x1,int y1,int x2,int y2);
        void drawRectangle(int x1,int y1,int x2,int y2);
        void drawRoundRect(int x1,int y1,int x2,int y2,int arcSize);
        void drawPolygon(point *points,int num);
        void drawPolyline(point *points,int num);
        void drawText(int x,int y,const char *str);
        char getKey();
        bool leftMouseDown();
        bool mediumMouseDown();
        bool rightMouseDown();
        void clear();
        void erase(int x1,int y1,int x2,int y2);
        void fillRect(int x1,int y1,int x2,int y2);
        void drawBitmap(int x,int y,const char* address);
        color getPixelColor(int x,int y);
        int getWidth();
        int getHeight();
        string getTitle();
        point getWindowPos();
        void hide();
        void resize(int _width,int _height);
        void setPen(int w,color col);
        void setBrush(color col);
        void setPen(HPEN hp);
        void setBrush(HBRUSH hb);
        point getMousePos();
        void getMousePos(int &x,int &y);
        void setMousePos(point p);
        void setMousePos(int x,int y);
        void maxSize();
        void fullScreen();
        void normalScreen();
        char key;
        int clickingButton();//NONE=0,LMB=1,MMB=2,RMB=4,L+M=3,L+R=5,M+R=6,L+M+R=7
        bool lb,mb,rb;
        HWND getHwnd();
        void setHwnd(HWND Hwnd);
    protected:

    private:
        int width,height;
        HBITMAP bitm;
        HPEN pen;
        HBRUSH brush;
	    string title;
	    HWND hwnd;
   	 	MSG messages;
		WNDCLASSEX wincl;
    	HDC hdc;
        //void defKeyDown(char key,in);
        //void defKeyUp();
        //void defMouseDown(char);
        //void defMouseUp();
};
extern point XY(int x,int y);
#endif // WINDOW_H
