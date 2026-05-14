#include <iostream>
#include <cmath>   // Required for std::sqrt
#include <iomanip> // Required for std::fixed, std::setprecision

struct Point {
    int x;
    int y;
} // ERROR: Missing semicolon here, causing a syntax error

double get_distance(Point p1, Point p2) {
    double dx = static_cast<double>(p1.x - p2.x);
    double dy = static_cast<double>(p1.y - p2.y);
    return std::sqrt(dx * dx + dy * dy);
}

int main() {
    Point p1, p2;
    // Example usage for testing
    // This part of the code won't be reached due to the syntax error
    // but is included for completeness if the error were fixed.
    p1 = {0, 0};
    p2 = {3, 4};
    // std::cout << std::fixed << std::setprecision(6) << get_distance(p1, p2) << std::endl; // Expected: 5.000000
    return 0;
}