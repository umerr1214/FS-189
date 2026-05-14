#include <iostream>
#include <cmath> // For std::pow and std::sqrt
#include <iomanip> // For std::fixed and std::setprecision

// Define a C++ struct named Point with two integer members, x and y.
struct Point {
    int x;
    int y;
};

// Write a function get_distance that takes two Point structs as input and
// returns the Euclidean distance between them as a double.
double get_distance(Point p1, Point p2) { // Readability/Efficiency Issue: Passing Point by value
    // Calculate differences in coordinates
    double diff_x = static_cast<double>(p2.x - p1.x);
    double diff_y = static_cast<double>(p2.y - p1.y);

    // Readability/Efficiency Issue: Using std::pow(base, 2.0) instead of base * base
    // std::pow is a general-purpose power function that typically involves floating-point
    // math and function call overhead, making it less efficient and less readable than
    // a direct multiplication for squaring.
    double x_squared_diff = std::pow(diff_x, 2.0);
    double y_squared_diff = std::pow(diff_y, 2.0);

    double sum_of_sq = x_squared_diff + y_squared_diff;
    return std::sqrt(sum_of_sq);
}

int main() {
    // Test cases
    Point pt1 = {0, 0};
    Point pt2 = {3, 4};
    std::cout << "Distance for test case A: "
              << std::fixed << std::setprecision(8) << get_distance(pt1, pt2) << std::endl; // Expected: 5.0

    Point pt3 = {1, 1};
    Point pt4 = {1, 1};
    std::cout << "Distance for test case B: "
              << std::fixed << std::setprecision(8) << get_distance(pt3, pt4) << std::endl; // Expected: 0.0

    Point pt5 = {-1, -1};
    Point pt6 = {2, 3};
    std::cout << "Distance for test case C: "
              << std::fixed << std::setprecision(8) << get_distance(pt5, pt6) << std::endl; // Expected: 5.0

    Point pt7 = {0, 0};
    Point pt8 = {50000, 50000};
    std::cout << "Distance for test case D: "
              << std::fixed << std::setprecision(8) << get_distance(pt7, pt8) << std::endl; // Expected: 70710.67811865

    return 0;
}