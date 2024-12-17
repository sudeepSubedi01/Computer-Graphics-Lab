#include<iostream>
#include<cmath>
#include<graphics.h>
using namespace std;

void dda(){
    float x1, x2, y1, y2;
    int steps;

    cout << "Enter first coordinates (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter second coordinates (x2 y2): ";
    cin >> x2 >> y2;

    float c = y2 - y1;
    float d = x2 - x1;
    float m = c / d;

    if (abs(c) > abs(d)) {
        steps = abs(c);
    } else {
        steps = abs(d);
    }

    float xin = d / (float)steps;
    float yin = c / (float)steps;

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
