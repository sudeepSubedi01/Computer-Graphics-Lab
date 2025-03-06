#include <iostream>
#include <graphics.h>
using namespace std;

bool clipTest(float p, float q, float &tIn, float &tOut) {
    if (p == 0) {
     
        return q >= 0;
    }
    float t = q / p;
    if (p < 0) {
        
        if (t > tOut) return false;
        if (t > tIn) tIn = t;
    } else {
      
        if (t < tIn) return false; 
        if (t < tOut) tOut = t;
    }
    return true;
}

void liangBarsky(float x1, float y1, float x2, float y2, float xmin, float xmax, float ymin, float ymax) {
    float tIn = 0.0, tOut = 1.0;
    float dx = x2 - x1, dy = y2 - y1;

  
//    setcolor(WHITE);
    line(x1, y1, x2, y2);


    cleardevice();
    setcolor(BLACK);
    rectangle(xmin, ymin, xmax, ymax); 

    if (clipTest(-dx, x1 - xmin, tIn, tOut) && // Left
        clipTest(dx, xmax - x1, tIn, tOut) && // Right
        clipTest(-dy, y1 - ymin, tIn, tOut) && // Bottom
        clipTest(dy, ymax - y1, tIn, tOut)) { 

      
        float xClip1 = x1 + tIn * dx;
        float yClip1 = y1 + tIn * dy;
        float xClip2 = x1 + tOut * dx;
        float yClip2 = y1 + tOut * dy;

//        setcolor(WHITE);
        line(xClip1, yClip1, xClip2, yClip2);
    }
}

void drawWindow() {
//    setcolor(WHITE);
    rectangle(150, 100, 450, 350);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    
    setbkcolor(WHITE);
    cleardevice();
    setcolor(BLACK);

    float x1, y1, x2, y2;
    cout << "Enter first coordinates (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter second coordinates (x2 y2): ";
    cin >> x2 >> y2;
	
    drawWindow();
//    setcolor(WHITE);
    line(x1,y1,x2,y2);
    delay(1000);
    liangBarsky(x1, y1, x2, y2, 150, 450, 100, 350);
	
	
    getch();
    closegraph();
    return 0;
}


