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
        window(char* title,int width,int height);
        bool update();
        virtual ~window();
        void show();
        void destroy();
        bool isQuiting();
        void drawLine(int x1,int y1,int x2,int y2,int width,color col);
        void drawEllipse(int x1,int y1,int x2,int y2,int linewidth,color line,color fill);
        void drawRectangle(int x1,int y1,int x2,int y2,int linewidth,color line,color fill);
        void drawRoundRect(int x1,int y1,int x2,int y2,int linewidth,int arcSize,color line,color fill);
        void drawPolygon(point *points,int num,int linewidth,color line,color fill);
        void drawPolyline(point *points,int num,int linewidth,color line);
        void drawText(int x,int y,const char *str,color col);
        void drawText(int x,int y,string str,color col);
        char getKey();
        bool leftMouseDown();
        bool mediumMouseDown();
        bool rightMouseDown();
        void clear();
        void erase(int x1,int y1,int x2,int y2);
        void fillRect(int x1,int y1,int x2,int y2,color col);
        void drawBitmap(int x,int y,char* address);
        color getPixelColor(int x,int y);
        int getWidth();
        int getHeight();
        void change(char* title,int _width,int _height);
    protected:
		
    private:
        int width,height;
        char key;
        void setPen(int w,color col);
        void setBrush(color col);
        HBITMAP bitm;
        HPEN pen;
        HBRUSH brush;
    HWND hwnd;
    MSG messages;
    WNDCLASSEX wincl;
    HDC hdc;

};
extern point XY(int x,int y);
#endif // WINDOW_H
