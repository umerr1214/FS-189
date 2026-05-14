#include <iostream>
#include <cmath>   // Required for std::sqrt
#include <iomanip> // Required for std::fixed, std::setprecision

struct Point {
    int x;
    int y;
};

// This function has a semantic error: it returns an int, truncating the double result.
// The return type should be `double` as per the question.
int get_distance(Point p1, Point p2) { // Semantic error: Return type is int, should be double
    double dx = static_cast<double>(p1.x - p2.x);
    double dy = static_cast<double>(p1.y - p2.y);
    double distance_squared = dx * dx + dy * dy;
    double euclidean_distance = std::sqrt(distance_squared);
    // The result is truncated when cast to int.
    return static_cast<int>(euclidean_distance);
}

int main() {
    Point p1, p2;
    // Example usage
    p1 = {0, 0};
    p2 = {3, 4};
    std::cout << "Distance between (0,0) and (3,4): " << std::fixed << std::setprecision(6) << static_cast<double>(get_distance(p1, p2)) << std::endl; // Expected: 5.000000, Actual: 5.000000 (correct by coincidence)

    p1 = {0, 0};
    p2 = {1, 1};
    std::cout << "Distance between (0,0) and (1,1): " << std::fixed << std::setprecision(6) << static_cast<double>(get_distance(p1, p2)) << std::endl; // Expected: 1.414214, Actual: 1.000000 (truncation)

    p1 = {0, 0};
    p2 = {2, 1};
    std::cout << "Distance between (0,0) and (2,1): " << std::fixed << std::setprecision(6) << static_cast<double>(get_distance(p1, p2)) << std::endl; // Expected: 2.236068, Actual: 2.000000 (truncation)
    return 0;
}