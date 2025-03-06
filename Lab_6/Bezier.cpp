#include <graphics.h>
#include <conio.h>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// Function to compute factorial (used for binomial coefficient)
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to compute the binomial coefficient (n choose k)
int binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Function to compute the Bernstein polynomial for any number of points
void drawBezier(vector<int> xPoints, vector<int> yPoints) {
    int n = xPoints.size();
    int x, y;

    // Loop for t from 0 to 1
    for (float t = 0; t <= 1; t += 0.001) {
        x = 0;
        y = 0;

        // Calculate the Bernstein polynomial for each control point
        for (int i = 0; i < n; i++) {
            int binom = binomialCoefficient(n - 1, i);
            float basis = pow(1 - t, n - 1 - i) * pow(t, i);
            x += binom * basis * xPoints[i];
            y += binom * basis * yPoints[i];
        }

        // Plot the point (x, y) on the screen
        putpixel(x, y, BLACK);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    
    setbkcolor(WHITE);
    cleardevice(); 
    setcolor(BLACK);

    // Define control points for the Bezier curve (any number of points)
    vector<int> xPoints;
    vector<int> yPoints;

//     1 point (single control point)
//    xPoints.push_back(200);  
//    yPoints.push_back(300);

    // 2 points (line between two control points)
//    xPoints.push_back(100);
//    xPoints.push_back(500);  
//    yPoints.push_back(500);
//    yPoints.push_back(500);

    // 3 points (quadratic Bezier curve)
//    xPoints.push_back(100);
//    xPoints.push_back(300);  
//    xPoints.push_back(500);
//    yPoints.push_back(500);
//    yPoints.push_back(100);
//    yPoints.push_back(500);

	// 4 points
//	xPoints.push_back(100);
//    xPoints.push_back(150);
//    xPoints.push_back(400);
//    xPoints.push_back(500);
//    yPoints.push_back(500);
//    yPoints.push_back(100);
//    yPoints.push_back(100);
//    yPoints.push_back(500);

    // 5 points (cubic Bezier curve)
//    xPoints.push_back(100);
//    xPoints.push_back(200);  
//    xPoints.push_back(300);
//    xPoints.push_back(400);
//    xPoints.push_back(500);
//    yPoints.push_back(500);
//    yPoints.push_back(300);
//    yPoints.push_back(100);
//    yPoints.push_back(300);
//    yPoints.push_back(500);

//    xPoints.push_back(150);
//    xPoints.push_back(250);  
//    xPoints.push_back(400);
//    yPoints.push_back(300);
//    yPoints.push_back(50);
//    yPoints.push_back(300);
    
//        xPoints.push_back(100);
//    xPoints.push_back(200);
//    xPoints.push_back(350);
//    xPoints.push_back(450);
//    yPoints.push_back(450);
//    yPoints.push_back(100);
//    yPoints.push_back(200);
//    yPoints.push_back(450);
    
        xPoints.push_back(50);
    xPoints.push_back(150);  
    xPoints.push_back(250);
    xPoints.push_back(350);
    xPoints.push_back(450);
    yPoints.push_back(450);
    yPoints.push_back(100);
    yPoints.push_back(200);
    yPoints.push_back(200);
    yPoints.push_back(450);

    // Draw the Bezier curve
    drawBezier(xPoints, yPoints);

    // Draw the control points and lines for reference
    setcolor(RED);
    for (int i = 0; i < xPoints.size(); i++) {
        circle(xPoints[i], yPoints[i], 5);
        if (i < xPoints.size() - 1) {
            line(xPoints[i], yPoints[i], xPoints[i + 1], yPoints[i + 1]);
        }
    }

    // Wait for the user to press a key
    getch();

    // Close the graphics mode
    closegraph();

    return 0;
}

