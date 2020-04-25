#ifndef BITMAP_HPP_INCLUDED
#define BITMAP_HPP_INCLUDED

#include "def.hpp"

class bitmap{
    public:
        bitmap();
        bitmap(const char* name);
        void setImg(const char* name);
        HDC getDc();
        int getWidth();
        int getHeight();
    private:
        int width,height;
        HDC hdc;

};

bitmap::bitmap(){
    width=height=0;
}

bitmap::bitmap(const char* name){
    hdc  = CreateCompatibleDC(GetDC(desktopHwnd));
    HBITMAP hbmp;
    BITMAP bmp;
    hbmp = (HBITMAP)LoadImage(NULL, name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE|LR_CREATEDIBSECTION);
    GetObject(hbmp, sizeof(BITMAP), &bmp);
    SelectObject(hdc, hbmp);
    width=bmp.bmWidth;
    height=bmp.bmHeight;
}

void bitmap::setImg(const char* name){
    hdc  = CreateCompatibleDC(GetDC(desktopHwnd));
    HBITMAP hbmp;
    BITMAP bmp;
    hbmp = (HBITMAP)LoadImage(NULL, name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE|LR_CREATEDIBSECTION);
    GetObject(hbmp, sizeof(BITMAP), &bmp);
    SelectObject(hdc, hbmp);
    width=bmp.bmWidth;
    height=bmp.bmHeight;
}

HDC bitmap::getDc(){
    return hdc;
}

int bitmap::getWidth(){
    return width;
}
int bitmap::getHeight(){
    return height;
}

#endif // BITMAP_HPP_INCLUDED
