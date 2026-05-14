#include <iostream>
#include <cmath> // For std::sqrt
#include <iomanip> // For std::fixed and std::setprecision

// Define a C++ struct named Point with two integer members, x and y.
struct Point {
    int x;
    int y;
};

// Write a function get_distance that takes two Point structs as input and
// returns the Euclidean distance between them as a double.
// Correct Version: Uses const references for efficiency and robust calculation.
double get_distance(const Point& p1, const Point& p2) {
    // Calculate differences in coordinates
    // Cast to double *before* squaring to prevent potential intermediate integer overflow
    // and ensure floating-point arithmetic for squares.
    double dx = static_cast<double>(p2.x - p1.x);
    double dy = static_cast<double>(p2.y - p1.y);

    // Calculate sum of squares using efficient and robust direct multiplication
    double sum_of_squares = (dx * dx) + (dy * dy);

    // Return the square root of the sum
    return std::sqrt(sum_of_squares);
}

int main() {
    // Test cases
    Point p1_a = {0, 0};
    Point p2_a = {3, 4};
    std::cout << "Distance between (" << p1_a.x << "," << p1_a.y << ") and (" << p2_a.x << "," << p2_a.y << "): "
              << std::fixed << std::setprecision(8) << get_distance(p1_a, p2_a) << std::endl; // Expected: 5.0

    Point p1_b = {1, 1};
    Point p2_b = {1, 1};
    std::cout << "Distance between (" << p1_b.x << "," << p1_b.y << ") and (" << p2_b.x << "," << p2_b.y << "): "
              << std::fixed << std::setprecision(8) << get_distance(p1_b, p2_b) << std::endl; // Expected: 0.0

    Point p1_c = {-1, -1};
    Point p2_c = {2, 3};
    std::cout << "Distance between (" << p1_c.x << "," << p1_c.y << ") and (" << p2_c.x << "," << p2_c.y << "): "
              << std::fixed << std::setprecision(8) << get_distance(p1_c, p2_c) << std::endl; // Expected: 5.0

    Point p1_d = {0, 0};
    Point p2_d = {50000, 50000};
    std::cout << "Distance between (" << p1_d.x << "," << p1_d.y << ") and (" << p2_d.x << "," << p2_d.y << "): "
              << std::fixed << std::setprecision(8) << get_distance(p1_d, p2_d) << std::endl; // Expected: 70710.67811865

    return 0;
}