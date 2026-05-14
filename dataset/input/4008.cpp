#include <iostream>
#include <cmath> // For sqrt
#include <iomanip> // For std::fixed and std::setprecision

// Define struct Point
struct Point {
    int x;
    int y;
};

// Function to calculate Euclidean distance (SEMANTIC ERROR: returns int, truncating double result)
int calculateDistance(Point p1, Point p2) { // Should be double, but returns int
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    // The result of std::sqrt is a double, but it's explicitly cast to int,
    // causing truncation of any decimal part before being returned.
    return static_cast<int>(std::sqrt(dx * dx + dy * dy));
}

int main() {
    // Create two Point objects that result in a non-integer distance
    Point p1 = {0, 0};
    Point p2 = {1, 1}; // Euclidean distance is sqrt(2) approx 1.4142...

    // Calculate and display the distance
    // The 'distance' variable is double, but the value assigned to it is
    // already truncated by the calculateDistance function.
    double distance = calculateDistance(p1, p2);
    std::cout << std::fixed << std::setprecision(10); // To clearly show the truncated double value
    std::cout << "The distance between (" << p1.x << ", " << p1.y << ") and ("
              << p2.x << ", " << p2.y << ") is: " << distance << std::endl; // Will output 1.0000000000

    return 0;
}