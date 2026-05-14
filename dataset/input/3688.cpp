#include <iostream>
#include <cmath> // For sqrt and pow
#include <iomanip> // For setprecision

struct Point {
    double x;
    double y;
} // SYNTAX ERROR: Missing semicolon here

int main() {
    Point p1, p2;

    std::cout << "Enter coordinates for Point 1 (x y): ";
    std::cin >> p1.x >> p1.y;

    std::cout << "Enter coordinates for Point 2 (x y): ";
    std::cin >> p2.x >> p2.y;

    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;

    double distance = std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The Euclidean distance between (" << p1.x << ", " << p1.y << ") and ("
              << p2.x << ", " << p2.y << ") is " << distance << std::endl;

    return 0;
}