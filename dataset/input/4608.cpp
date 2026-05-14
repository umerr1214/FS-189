#include <iostream>
#include <cmath> // Required for sqrt

// Define a C++ struct Point
struct Point {
    int x;
    int y;
};

// Function to calculate Euclidean distance, but returns int instead of double
// This is a semantic error as the problem specifies a double return type
int calculateDistance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    // The result of sqrt is cast to int due to the function's return type, losing precision
    return static_cast<int>(std::sqrt(dx * dx + dy * dy));
}

int main() {
    // Demonstrate creating Point objects
    Point p1_main = {0, 0};
    Point p2_main = {3, 4};

    // Calculate and print the distance
    std::cout << "Distance between (" << p1_main.x << "," << p1_main.y << ") and ("
              << p2_main.x << "," << p2_main.y << ") is: "
              << calculateDistance(p1_main, p2_main) << std::endl; // Output will be truncated

    Point p3_main = {10, 20};
    Point p4_main = {13, 24};
    std::cout << "Distance between (" << p3_main.x << "," << p3_main.y << ") and ("
              << p4_main.x << "," << p4_main.y << ") is: "
              << calculateDistance(p3_main, p4_main) << std::endl; // Output will be truncated

    Point p5_main = {-1, -1};
    Point p6_main = {1, 1};
    std::cout << "Distance between (" << p5_main.x << "," << p5_main.y << ") and ("
              << p6_main.x << "," << p6_main.y << ") is: "
              << calculateDistance(p5_main, p6_main) << std::endl; // Output will be truncated

    return 0;
}