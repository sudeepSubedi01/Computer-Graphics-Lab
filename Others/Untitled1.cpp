#include <graphics.h>
#include <iostream>
using namespace std;

// Function to plot symmetric points in all octants but print only the 4th quadrant points
void drawCirclePoints(int xc, int yc, int x, int y) {
    // Only plot and print points in the fourth quadrant
    if (x >= 0 && y <= 0) {
        putpixel(xc + x, yc + y, WHITE);  // Plot the point on the screen
        cout << "(" << xc + x << ", " << yc + y << ")\n";  // Print the point coordinates
    }
}

// Midpoint Circle Algorithm using decision parameter
void midpointCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int p = 1 - r;  // Initial decision parameter

    drawCirclePoints(xc, yc, x, y);  // Plot initial point and print

    while (x < y) {
        x++;

        if (p < 0) {
            p = p + 2 * x + 1;  // Case when p_k < 0
        } else {
            y--;
            p = p + 2 * x - 2 * y + 1;  // Case when p_k >= 0
        }

        // Plot points in the fourth quadrant only and print the coordinates
        drawCirclePoints(xc, yc, x, y);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc, yc, r;
    cout << "Enter center (x, y): ";
    cin >> xc >> yc;
    cout << "Enter radius: ";
    cin >> r;

    midpointCircle(xc, yc, r);

    getch();
    closegraph();
    return 0;
}

