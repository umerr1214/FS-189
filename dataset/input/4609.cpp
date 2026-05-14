#include <iostream>
#include <cmath> // For std::sqrt and std::pow
#include <limits> // For std::numeric_limits

struct Point {
    int x;
    int y;
};

// This version uses std::pow which operates on doubles and can introduce
// slight precision errors for large integer inputs, making it less robust
// than direct multiplication for squaring integers.
double calculateDistance(Point p1, Point p2) {
    // Calculate differences as doubles to be used with std::pow.
    // Casting to double here before subtraction ensures the difference is calculated
    // in floating point, preventing potential int overflow if the difference is very large.
    double dx = static_cast<double>(p1.x) - p2.x;
    double dy = static_cast<double>(p1.y) - p2.y;

    // Using std::pow for squaring. While mathematically correct,
    // for integer-derived arguments, direct multiplication (dx * dx) is
    // generally more robust against floating-point precision issues
    // and often more efficient.
    double distance_sq = std::pow(dx, 2) + std::pow(dy, 2);

    return std::sqrt(distance_sq);
}

int main() {
    Point p1 = {0, 0};
    Point p2 = {3, 4};
    std::cout.precision(6);
    std::cout << std::fixed << "Distance between (" << p1.x << ", " << p1.y << ") and (" << p2.x << ", " << p2.y << "): "
              << calculateDistance(p1, p2) << std::endl;

    Point p3 = {-10, -20};
    Point p4 = {20, 10};
    std::cout << std::fixed << "Distance between (" << p3.x << ", " << p3.y << ") and (" << p4.x << ", " << p4.y << "): "
              << calculateDistance(p3, p4) << std::endl;

    // Test case with large coordinates to demonstrate potential precision/robustness concerns
    // if `double` precision limits were hit by `std::pow` for specific integer squares.
    // For `int` limits, `double` generally has sufficient precision, but `std::pow` is a less robust choice.
    Point p5 = {std::numeric_limits<int>::max(), 0};
    Point p6 = {std::numeric_limits<int>::min(), 0};
    std::cout << std::fixed << "Distance between (" << p5.x << ", " << p5.y << ") and (" << p6.x << ", " << p6.y << "): "
              << calculateDistance(p5, p6) << std::endl;

    return 0;
}