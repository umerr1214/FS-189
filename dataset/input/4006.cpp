#include <iostream>
#include <cmath> // For sqrt

// Define struct Point
struct Point {
    int x;
    int y;
} // SYNTAX ERROR: Missing semicolon here

// Function to calculate Euclidean distance
double calculateDistance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return std::sqrt(dx * dx + dy * dy);
}

int main() {
    // Create two Point objects
    Point p1 = {1, 1};
    Point p2 = {4, 5};

    // Calculate and display the distance
    double distance = calculateDistance(p1, p2);
    std::cout << "The distance between (" << p1.x << ", " << p1.y << ") and ("
              << p2.x << ", " << p2.y << ") is: " << distance << std::endl;

    return 0;
}