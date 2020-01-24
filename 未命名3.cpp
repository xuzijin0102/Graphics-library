#include<bits/stdc++.h>
#include<utility>
#include<queue>
#include<conio.h>
#define in(x,y) ((x>=0&&y>=0)&&(x<1000&&y<1000))
#include"window.h"
using namespace std;
bool used[4000][4000];
void bfs(window w)
{
	queue<pair<int,int> > q;
	used[100][100]=0;
	while(w.update())
	{
		int mx,my;
		getMousePos(mx,my);
		if(w.leftMouseDown()){
			q.push(make_pair(mx,my));
		}
		if(q.empty())continue;
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		if(!in(x,y))
			continue;
		if(used[x][y])
			continue;
		used[x][y]=1;
		w.drawPixel(x,y,RED);
		if(!used[x+1][y])
		q.push(make_pair(x+1,y));
		//q.push(make_pair(x+1,y+1));
		if(!used[x][y+1])
		q.push(make_pair(x,y+1));
		q.push(make_pair(x-1,y+1));
		//if(!used[x-1][y])
		q.push(make_pair(x-1,y));
		if(!used[x][y-1])
		q.push(make_pair(x,y-1));
		//q.push(make_pair(x+1,y-1));
		//q.push(make_pair(x-1,y-1));
		for(int i=0;i<100000;i++);
	}
}
int demo1()
{
	srand(time(0));
	window w("bfs demo",1000,1000);
	w.show();
	w.setBrush(BLACK);
	w.setPen(1,BLACK);
	int x=4000,y=4000;
	while(!w.leftMouseDown())
	{
		w.update();
		int rndx=rand()%4000;
		int rndy=rand()%4000;
		used[rndx][rndy]=1;
		w.drawPixel(rndx,rndy,BLACK);
	}
	bfs(w);
	while(w.update());
	return 0;
}
int demo2()
{
	window w;
	w.messagebox("Hello","Hello",1);
	w.show();
	w.create_button("hello",0,0,100,100,3301);
	w.create_button("hello",0,100,100,100,2);
	while(w.update())
	{
		if(w.on_button_click(3301)==1)
			w.messagebox("Hello","Hello",1);
	}
}
int main()
{
	return demo2();
}
