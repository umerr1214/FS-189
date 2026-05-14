#include <iostream>
#include <cmath>
#include <iomanip>

// Define a struct Point with x and y (double) coordinates
struct Point {
    double x = 0.0; // Initialize to 0.0 to ensure predictable behavior
    double y = 0.0; // even when cin fails, avoiding undefined behavior.
                    // This allows the program to "run correctly"
                    // but produce incorrect results silently,
                    // demonstrating a robustness issue.
};

int main() {
    Point p1, p2;

    std::cout << "Enter coordinates for Point 1 (x y): ";
    // Robustness Issue: No input validation or error handling for std::cin.
    // If the user enters non-numeric input, cin will fail,
    // and p1.x will retain its default value (0.0).
    // Subsequent reads will also fail, leaving p1.y, p2.x, p2.y at 0.0.
    // The program will then proceed with these incorrect values.
    std::cin >> p1.x >> p1.y;

    std::cout << "Enter coordinates for Point 2 (x y): ";
    std::cin >> p2.x >> p2.y;

    // Calculate Euclidean distance
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double distance = std::sqrt(dx * dx + dy * dy);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "The Euclidean distance between the two points is: " << distance << std::endl;

    return 0;
}