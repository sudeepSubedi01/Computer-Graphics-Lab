#include<stdio.h>
#include<conio.h>
#include<graphics.h>
using namespace std;

#define LEFT 1
#define RIGHT 2
# define BOTTOM 4
# define TOP 8
int computeCode(int x,int y,int x_min,int y_min, int x_max, int y_max)
{
	int code=0;
	if(x<x_min) code|=LEFT;
	else if(x>x_max) code|=RIGHT;
	if(y<y_min) code|=BOTTOM;
	else if(y>y_max) code|=TOP;
	return code;
}

void CohenSutherland(int x_min,int y_min, int x_max, int y_max,int x1,int y1,int x2,int y2)
{
	int code1=computeCode(x1,y1,x_min,y_min,x_max,y_max);
	int code2=computeCode(x2,y2,x_min,y_min,x_max,y_max);
	
	int accept=0;
	while(1)
	{
		if((code1==0)&& (code2==0))
		{
			accept=1;
			break;
		}else if (code1 & code2)
		{
			break;
		}else{
			int codeOut;
			int x,y;
			if(code1!=0) codeOut=code1;
			else codeOut=code2;
		
		if(codeOut & TOP){
			x=x1+(x2-x1)*(y_max-y1)/(y2-y1);
			y=y_max;
		}
		else if(codeOut & BOTTOM){
			x=x1+(x2-x1)*(y_min-y1)/(y2-y1);
			y=y_min;
		}
			else if(codeOut & RIGHT){
			y=y1+(y2-y1)*(x_max-x1)/(x2-x1);
			x=x_max;
		}
			else if(codeOut & LEFT){
			y=y1+(y2-y1)*(x_min-x1)/(x2-x1);
			x=x_min;
		}
		if(codeOut==code1)
		{
			x1=x;
			y1=y;
			code1=computeCode(x1,y1,x_min,y_min,x_max,y_max);
		}
		else{
			x2=x;
			y2=y;
			code2=computeCode(x2,y2,x_min,y_min,x_max,y_max);
		}
	}
}
if(accept)
{
	setbkcolor(WHITE);
	setcolor(BLACK);
//	line(x1,y1,x2,y2);
//	setbkcolor(WHITE);
//	setcolor(BLACK);
	line(x1,y1,x2,y2);
	printf("clipped line:((%d,%d) to (%d,%d))",x1,y1,x2,y2);

}
else{
	printf("completely outside window");
}
}


int main(){ 
	int gd=DETECT, gm;
	initgraph(&gd,&gm,(char*)"");
	
	setbkcolor(WHITE);
	cleardevice();
	setcolor(BLACK);
	
	int x_min=100,y_min=100,x_max=300,y_max=300;
	int x1,y1,x2,y2;
	printf("Enter first coordinates (x1,y1): ");
	scanf("%d%d",&x1,&y1);
	printf("Enter second coordinates (x2,y2): ");
	scanf("%d%d",&x2,&y2);
	
//	setbkcolor(WHITE);
//	setcolor(BLACK);
	rectangle(x_min,y_min,x_max,y_max);
	line(x1,y1,x2,y2);
	delay(1000);
	
	cleardevice();
//	setbkcolor(WHITE);
//	setcolor(BLACK);
	rectangle(x_min,y_min,x_max,y_max);
	CohenSutherland(x_min,y_min,x_max,y_max,x1,y1,x2,y2);
	
	getch();
	closegraph();
	return 0;
}

