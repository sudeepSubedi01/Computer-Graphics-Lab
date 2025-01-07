#include <iostream>
#include <graphics.h> // For graphics functions in C++
using namespace std;

void midpointEllipse(int xc, int yc, int rx, int ry) {
    // Step 4: Initial coordinates for the first point on the ellipse
    int x = 0;
    int y = ry;

    // Step 5: Initialize the decision parameter in region 1
    int p1 = ry * ry - rx * rx * ry + (1 / 4) * rx * rx;

    // Step 6: Region 1 - Loop until we reach the decision boundary between regions
    while (2 * ry * ry * x <= 2 * rx * rx * y) {
        // Add the points for all four quadrants based on symmetry
        putpixel(xc + x, yc + y, WHITE);  // 1st quadrant
        putpixel(xc - x, yc + y, WHITE);  // 2nd quadrant
        putpixel(xc + x, yc - y, WHITE);  // 3rd quadrant
        putpixel(xc - x, yc - y, WHITE);  // 4th quadrant

        // Check the decision parameter
        if (p1 < 0) {
            // Move in the x direction (x + 1)
            x += 1;
            // Keep the y coordinate the same
            y = y;
            // Update the decision parameter for region 1
            p1 += 2 * ry * ry * x + ry * ry;
        } else {
            // Move in both x and y directions (x + 1, y - 1)
            x += 1;
            y -= 1;
            // Update the decision parameter for region 1
            p1 += 2 * ry * ry * x - 2 * rx * rx * y + ry * ry;
        }
    }

    // Step 7: Initialize the decision parameter for region 2
    int p2 = ry * ry * (x + 1 / 2) * (x + 1 / 2) + rx * rx * (y - 1) * (y - 1) - rx * rx * ry * ry;

    // Step 8: Region 2 - Loop until y becomes negative
    while (y >= 0) {
        // Add the points for all four quadrants based on symmetry
        putpixel(xc + x, yc + y, WHITE);  // 1st quadrant
        putpixel(xc - x, yc + y, WHITE);  // 2nd quadrant
        putpixel(xc + x, yc - y, WHITE);  // 3rd quadrant
        putpixel(xc - x, yc - y, WHITE);  // 4th quadrant

        // Check the decision parameter
        if (p2 > 0) {
            // Move in the y direction (y - 1)
            y -= 1;
            // Keep the x coordinate the same
            x = x;
            // Update the decision parameter for region 2
            p2 -= 2 * rx * rx * y + rx * rx;
        } else {
            // Move in both x and y directions (x + 1, y - 1)
            x += 1;
            y -= 1;
            // Update the decision parameter for region 2
            p2 += 2 * ry * ry * x - 2 * rx * rx * y + rx * rx;
        }
    }
}

int main() {
    // Step 3: Read the values for xc, yc, rx, ry
    int xc, yc, rx, ry;

    cout << "Enter the center x-coordinate (xc): ";
    cin >> xc;
    cout << "Enter the center y-coordinate (yc): ";
    cin >> yc;
    cout << "Enter the semi-major axis (rx): ";
    cin >> rx;
    cout << "Enter the semi-minor axis (ry): ";
    cin >> ry;

    // Initialize the graphics system
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    midpointEllipse(xc, yc, rx, ry);


    getch();
    closegraph();

    return 0;
}




/*
1. start
2. decalre xc,yc,rx,yx,x,y,p0,pk,pk+1
3. read values xc,yc,rx,ry
4. initialize x,y i.e set the coordincated for the first point on the circumference of the ellipse centered at origin as x = 0, y=ry
5. calculate the decision parameter in region 1: p10 = ry^2 -  rx^2 * ry + 1/4 * rx^2
6. at each xk position in region 1, starting from k=0
if p1k<0, then
xk+1 = xk + 1
yk+1 = yk 
p1k+1 = p1k + 2 * ry^2 * xk+1 + ry^2
else,
xk+1 = xk + 1
yk+1 = yk - 1
p1k+1 = p1k + 2 * ry^2 * xk+1 - 2 * rx^2 * yk+1 + ry^2
and continue until 2 * ry^2 * x >= 2* rx^2 * y
7. calculate the initital decision parameter in region 2 using the last point (x0,y0) calculated in region 1 as:
p20 = ry^2 * (x0 + 1/2)^2 + rx^2 * (y0-1)^2 - rx^2 * ry^2
8. at each yk position in region 2, starting at k = 0:
if p2k>0, then the next point along the ellipse centered on (0,0) is (xk,yk - 1) 
p2k+1 = p2k - 2 * rx^2 * yk+1 + rx^2
else,
xk+1 = xk + 1
yk+1 = yk - 1
p2k+1 = p2k + 2 * ry^2 * xk+1 - 2 * rx^2 * yk+1 + rx^2
use the same incremental calculation for x and y as in region 1

9. determine the symmetry in other three quadrants
10. move each calculated pixel position (x,y) onto the elliptical path centered on (xc,yc) : x = x + xc , y = y + yc
11. repeat the steps for region 2 until y<0
12. stop



*/
