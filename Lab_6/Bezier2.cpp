#include <graphics.h>
#include <conio.h>
#include <cmath>
#include <iostream>
using namespace std;

// Function to compute the Bernstein polynomial for cubic Bezier curve
void drawBezier(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    int x, y;
    // Loop for t from 0 to 1
    for (float t = 0; t <= 1; t += 0.001) {
        // Bernstein's cubic formula
        x = pow(1 - t, 3) * x0 + 3 * t * pow(1 - t, 2) * x1 + 3 * pow(t, 2) * (1 - t) * x2 + pow(t, 3) * x3;
        y = pow(1 - t, 3) * y0 + 3 * t * pow(1 - t, 2) * y1 + 3 * pow(t, 2) * (1 - t) * y2 + pow(t, 3) * y3;

        // Plot the point (x, y) on the screen
        putpixel(x, y, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Define control points for the Bezier curve
    int x0 = 100, y0 = 500;
    int x1 = 150, y1 = 100;
    int x2 = 400, y2 = 100;
    int x3 = 500, y3 = 500;

    // Draw the cubic Bezier curve
    drawBezier(x0, y0, x1, y1, x2, y2, x3, y3);

    // Draw the control points and lines for reference
    setcolor(RED);
    circle(x0, y0, 5);
    circle(x1, y1, 5);
    circle(x2, y2, 5);
    circle(x3, y3, 5);
    line(x0, y0, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);

    // Wait for the user to press a key
    getch();

    // Close the graphics mode
    closegraph();

    return 0;
}

