#include <iostream>
#include <cmath> // Required for sqrt

// Define a C++ struct Point
struct Point {
    int x;
    int y;
};

// Function to calculate Euclidean distance
double calculateDistance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    // Logical error: Forgetting to take the square root
    return (dx * dx + dy * dy);
}

int main() {
    // Demonstrate creating Point objects
    Point p1_main = {0, 0};
    Point p2_main = {3, 4};

    // Calculate and print the distance
    std::cout << "Distance between (" << p1_main.x << "," << p1_main.y << ") and ("
              << p2_main.x << "," << p2_main.y << ") is: "
              << calculateDistance(p1_main, p2_main) << std::endl;

    Point p3_main = {10, 20};
    Point p4_main = {13, 24};
    std::cout << "Distance between (" << p3_main.x << "," << p3_main.y << ") and ("
              << p4_main.x << "," << p4_main.y << ") is: "
              << calculateDistance(p3_main, p4_main) << std::endl;

    return 0;
}