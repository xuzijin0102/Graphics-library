#include<bits/stdc++.h>
#include"window.h"
using namespace std;
int main()
{
	window w;
	w.show();
	Sleep(1000);
	w.destroy();
	w.change("shit",1000,1000);
	w.show();
	//Sleep(10000);
	int x=0,y=400;
	while(w.update())
	{
		w.drawEllipse(x,y,x+4,y+4,1,RGB(0,0,0),RGB(0,0,0));
		x+=4;
		Sleep(10);
	}
	return 0;
}
