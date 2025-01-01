#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;

int main(){
  int gd = DETECT,gm,x1,y1,x2,y2,lx,ly,dx,dy,pk,i;
  initgraph(&gd,&gm, "");
  //initgraph(&gd,&gm, "c:\\tc\\bgi");
  cout<<"Enter values of x1 and y1"<<endl;
  cin>>x1>>y1;
  cout<<"Enter values of x2 and y2"<<endl;
  cin>>x2>>y2;
  dx = abs(x2-x1);
  dy = abs(y2-y1);

  if(x2>x1){
    lx=1;
  }
  else{
    lx = -1;
  }
  if(y2>y1){
    ly=1;
  }
  else{
    ly = -1;
  }

  putpixel(x1,y1,WHITE);
  if(dx>dy){
    pk = 2*dy-dx;
    for (i=0;i<dx;i++){
      if(pk<0){
        x1 = x1 +lx;
        y1 = y1;
        pk = pk + 2*dy;
      }
      else{
        x1 = x1 +lx;
        y1 = y1 + ly;
        pk = pk + 2*dy - 2*dx;
      }
      putpixel(x1,y1,WHITE);
      delay(10);
    }
  }
  else{
    pk = 2*dx-dy;
    for(i=0;i<dy;i++){
      if(pk<0){
        x1 = x1;
        y1 = y1 + ly;
        pk = pk + 2*dx;
      }
      else{
        x1 = x1 +lx;
        y1 = y1 + ly;
        pk = pk + 2*dx - 2*dy;
      }
      putpixel(x1,y1,WHITE);
      delay(10);
    }
  }
  getch();
  closegraph();

}
