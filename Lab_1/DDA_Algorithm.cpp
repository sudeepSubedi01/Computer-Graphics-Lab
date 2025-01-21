#include<iostream>
#include<cmath>
#include<graphics.h>
using namespace std;

void dda(){
    float x1, x2, y1, y2,xinc,yinc, dx,dy;
    int steps,i;

    cout << "Enter first coordinates (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter second coordinates (x2 y2): ";
    cin >> x2 >> y2;

    dy = y2 - y1;
    dx = x2 - x1;

    if (abs(dy) > abs(dx)) {
        steps = round(abs(dy));
    } else {
        steps = round(abs(dx));
    }

    xinc = dx / steps;
    yinc = dy / steps;
    
	cout<<"dx = "<<dx<<endl;
	cout<<"dy = "<<dy<<endl;
		
	cout<<"Steps = "<< steps<<endl;
	
	cout<<"xinc = "<<xinc<<endl;
	cout<<"yinc = "<<yinc<<endl;
	
	cout<<"Points Plotted: "<<endl;
	cout<<"Step\t(x,y)\t\t\tround((x,y))"<<endl;
	
    for (i = 0; i <= steps; i++) {
        putpixel(round(x1), round(y1), WHITE);
        cout<<i<<"\t("<<x1<<","<<y1<<")\t"<<"\t("<<round(x1)<<","<<round(y1)<<")\t"<<endl;
        delay(100);
        x1 = x1 + xinc;
        y1 = y1 + yinc;
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
