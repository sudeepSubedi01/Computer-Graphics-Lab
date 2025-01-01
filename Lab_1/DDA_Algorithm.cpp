#include<iostream>
#include<cmath>
#include<graphics.h>
using namespace std;

void dda(){
    float x1, x2, y1, y2,xin,yin;
    int steps,dx,dy;

    cout << "Enter first coordinates (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter second coordinates (x2 y2): ";
    cin >> x2 >> y2;

    dy = y2 - y1;
    dx = x2 - x1;

    if (abs(dy) > abs(dx)) {
        steps = abs(dy);
    } else {
        steps = abs(dx);
    }

    xin = dx / (float)steps;
    yin = dy / (float)steps;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x1), round(y1), WHITE);
        delay(10);  
        x1 = x1 + xin;
        y1 = y1 + yin;
    }
}

int main() {
    int gdriver = DETECT, gm;
    initgraph(&gdriver, &gm, NULL);  

    dda();  

    getch(); 
    closegraph();  

    return 0;  
}
