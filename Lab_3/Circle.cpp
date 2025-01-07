#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <math.h>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc, yc, r, x0, y0, p0, pk, pk1;

    // Step 3: Read values xc, yc, r
    cout << "Enter the center (x, y) of the circle: ";
    cin >> xc >> yc;

    cout << "Enter radius of the circle: ";
    cin >> r;

    // Step 4: Initialize x0, y0 for the first point on the circumference
    x0 = 0;
    y0 = r;

    // Step 5: Calculate the initial decision parameter p0
    p0 = 5 / 4 - r;
    pk = p0;  // Set pk = p0

    // Step 6: Plot the initial point (x0, y0) and its symmetrical points
    putpixel(xc + x0, yc - y0, WHITE);  // 1st octant
    putpixel(xc - x0, yc - y0, WHITE);  // 2nd octant
    putpixel(xc + x0, yc + y0, WHITE);  // 4th octant
    putpixel(xc - x0, yc + y0, WHITE);  // 3rd octant
    putpixel(xc + y0, yc - x0, WHITE);  // 5th octant
    putpixel(xc - y0, yc - x0, WHITE);  // 6th octant
    putpixel(xc + y0, yc + x0, WHITE);  // 7th octant
    putpixel(xc - y0, yc + x0, WHITE);  // 8th octant

    // Step 10: Loop to calculate the next points and plot them
    while (x0 < y0) {
        // Step 6 (contd): If pk < 0, the next point is (x0 + 1, y0)
        if (pk < 0) {
            x0 = x0 + 1;
            y0 = y0;
            pk1 = pk + 2 * x0 + 1;  // Update pk+1
        } else {  // Otherwise, the next point is (x0 + 1, y0 - 1)
            x0 = x0 + 1;
            y0 = y0 - 1;
            pk1 = pk + 2 * x0 - 2 * y0 + 1;  // Update pk+1
        }

        // Step 7: Plot the points in all octants
        putpixel(xc + x0, yc - y0, WHITE);  // 1st octant
        putpixel(xc - x0, yc - y0, WHITE);  // 2nd octant
        putpixel(xc + x0, yc + y0, WHITE);  // 4th octant
        putpixel(xc - x0, yc + y0, WHITE);  // 3rd octant
        putpixel(xc + y0, yc - x0, WHITE);  // 5th octant
        putpixel(xc - y0, yc - x0, WHITE);  // 6th octant
        putpixel(xc + y0, yc + x0, WHITE);  // 7th octant
        putpixel(xc - y0, yc + x0, WHITE);  // 8th octant

        // Update pk for the next iteration
        pk = pk1;
        
        delay(10);
    }

    getch();
    closegraph();
    return 0;
}


/*
1. start
2. decalre xc,yc,r,x0,y0,p0,pk,pk+1
3. read values xc,yc,r
4. initialize x0,y0 i.e set the coordincated for the first point on the circumference of the circle centered at origin as x0 = 0, y0=r
5. calculate the decision parameter: p0 = 5/4 - r
6. at each xk position, starting from k=0
if pk<0, then
xk+1 = xk + 1
yk+1 = yk 
pk+1 = pk + 2 xk+1 +1
else,
xk+1 = xk + 1
yk+1 = yk - 1
pk+1 = pk + 2 xk+1 - 2 yk+1 +1
7. determine the symmetry in other seven octants
8. move each calculated pixel position (x,y) onto the circular path centered on (xc,yc)
9. plot the coordinates: x = x + xc , y = y + yc
10. repeat 6 to 9 until x>=y
11. stop



*/


