#include <iostream>
#include <cmath>   // Required for std::abs (used incorrectly for Manhattan distance)
#include <iomanip> // Required for std::fixed, std::setprecision

struct Point {
    int x;
    int y;
};

// This function calculates Manhattan distance, not Euclidean distance.
// It's a logical error as it uses the wrong formula.
double get_distance(Point p1, Point p2) {
    double dx = std::abs(static_cast<double>(p1.x - p2.x)); // Should be (p1.x - p2.x) * (p1.x - p2.x)
    double dy = std::abs(static_cast<double>(p1.y - p2.y)); // Should be (p1.y - p2.y) * (p1.y - p2.y)
    return dx + dy; // Should be std::sqrt(dx*dx + dy*dy)
}

int main() {
    Point p1, p2;
    // Example usage
    p1 = {0, 0};
    p2 = {3, 4};
    std::cout << "Distance between (0,0) and (3,4): " << std::fixed << std::setprecision(6) << get_distance(p1, p2) << std::endl; // Expected: 5.000000, Actual: 7.000000

    p1 = {-1, -1};
    p2 = {2, 3};
    std::cout << "Distance between (-1,-1) and (2,3): " << std::fixed << std::setprecision(6) << get_distance(p1, p2) << std::endl; // Expected: 5.000000, Actual: 7.000000
    return 0;
}