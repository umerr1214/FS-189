#include <iostream>
// #include <cmath> // Missing include for std::sqrt, causing a semantic error
#include <iomanip> // For std::fixed, std::setprecision

// Define a struct named `Point` with two integer members, `x` and `y`.
struct Point {
    int x;
    int y;
};

// Write a function `distance` that takes two `Point` structs as input
// and returns the Euclidean distance between them.
double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    // Semantic error: `std::sqrt` is used without including <cmath>.
    // This will typically result in a 'use of undeclared identifier' or similar error.
    return std::sqrt(dx * dx + dy * dy);
}

int main() {
    std::cout << std::fixed << std::setprecision(6);

    Point p1 = {0, 0};
    Point p2 = {3, 4};
    std::cout << "Distance between (" << p1.x << "," << p1.y << ") and ("
              << p2.x << "," << p2.y << ") is: " << distance(p1, p2) << std::endl;

    Point p3 = {1, 1};
    Point p4 = {1, 1};
    std::cout << "Distance between (" << p3.x << "," << p3.y << ") and ("
              << p4.x << "," << p4.y << ") is: " << distance(p3, p4) << std::endl;

    Point p5 = {-1, -1};
    Point p6 = {2, 3};
    std::cout << "Distance between (" << p5.x << "," << p5.y << ") and ("
              << p6.x << "," << p6.y << ") is: " << distance(p5, p6) << std::endl;

    return 0;
}