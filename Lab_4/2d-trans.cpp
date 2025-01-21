#include <iostream>
#include <graphics.h>
#include <cmath>
#include <conio.h>
using namespace std;


void draw(int a[2][5]) {
    int i;
    for (i = 0; i < 4; i++) {
        line(a[0][i], a[1][i], a[0][i + 1], a[1][i + 1]);
    }
    line(a[0][4], a[1][4], a[0][0], a[1][0]);
}

void translate(int a[2][5]) {
    int tx, ty;
    cout << "Enter translation factors (tx ty): ";
    cin >> tx >> ty;
    for (int i = 0; i < 5; i++) {
        a[0][i] += tx;
        a[1][i] += ty;
    }
}

void scale(int a[2][5]) {
    int sx, sy;
    cout << "Enter scaling factors (sx sy): ";
    cin >> sx >> sy;
    for (int i = 0; i < 5; i++) {
        a[0][i] *= sx;
        a[1][i] *= sy;
    }
}

void rotate(int a[2][5]) {
    float angle;
    cout << "Enter rotation angle (in degrees): ";
    cin >> angle;
    angle = angle * 3.14 / 180.0;
    for (int i = 0; i < 5; i++) {
        int tempX = a[0][i];
        int tempY = a[1][i];
        a[0][i] = tempX * cos(angle) - tempY * sin(angle);
        a[1][i] = tempX * sin(angle) + tempY * cos(angle);
    }
}

void reflectX(int a[2][5]){
	cout<<"ReflectX";
	int i;
	for(i=0;i<5;i++){
		a[1][i] = -1 * a[1][i];
	}
}

void reflectY(int a[2][5]){
	cout<<"ReflectY";
	int i;
	for(i=0;i<5;i++){
		a[0][i] = -1 * a[0][i];
	}
}

void reflectO(int a[2][5]){
	int i;
	for(i=0;i<5;i++){
		a[1][i] = -1 * a[1][i];
		a[0][i] = -1 * a[0][i];
	}
}

int main() {
    int a[2][5], i;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");
    setbkcolor(WHITE);
    cleardevice();

    cout << "Enter the coordinates of the 5 points (x y):" << endl;
   a[0][0] = 100;
   a[1][0] = 100; 
   a[0][1] = 200; 
   a[1][1] = 100; 
   a[0][2] = 200; 
   a[1][2] = 200; 
   a[0][3] = 100; 
   a[1][3] = 200;
    a[0][4] = 100; 
	a[1][4] = 100;

//    for (i = 0; i < 2; i++) {
//    	cout<<"Enter two: ";
//        cin >> a[0][i] >> a[1][i];
//    }
	
	
	
    cout<<"Original Shape Drawn"<<endl;
   draw(a);
    
   cout<<endl<<endl;
   cout<<"-----Translation-----"<<endl;
   translate(a);
   cleardevice();
   setcolor(GREEN);
   draw(a);
   
   cout<<endl<<endl;
   cout<<"-----Scaling-----"<<endl;
   scale(a);
   cleardevice();
   setcolor(BLUE);
   draw(a);
   
   cout<<endl<<endl;
   cout<<"-----Rotation-----"<<endl;
   rotate(a);
   cleardevice();
   setcolor(GREEN);
   draw(a);
    
//    cout<<endl<<endl;
//    cout<<"-----Reflection across X-axis-----"<<endl;
//    reflectX(a);
//    cleardevice();
//    setcolor(BLUE);
//    draw(a);
    
//    cout<<endl<<endl;
//    cout<<"-----Reflection across Y-axis-----"<<endl;
//    reflectY(a);
//    cleardevice();
//    setcolor(GREEN);
//    draw(a);
    
//    cout<<endl<<endl;
//    cout<<"-----Reflection across Origin-----"<<endl;
//    reflectO(a);
//    cleardevice();
//    setcolor(BLUE);
//    draw(a);
	
    getch();
    closegraph();
    return 0;
}

