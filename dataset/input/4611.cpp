#include <iostream> // For std::cout, std::endl
#include <cmath>    // For std::sqrt
#include <iomanip>  // For std::fixed, std::setprecision
#include <limits>   // For std::numeric_limits

// Define the Point struct as required
struct Point {
    int x;
    int y;
};

// Function to calculate the Euclidean distance between two Point objects
// This version is correct, efficient, and robust.
double calculateDistance(Point p1, Point p2) {
    // Calculate differences in coordinates.
    // Cast to double *before* subtraction to prevent potential int overflow
    // if `p1.x - p2.x` exceeds `INT_MAX` or goes below `INT_MIN`.
    // This also ensures subsequent calculations are done in double precision,
    // which can accurately represent integer differences and their squares for the `int` range.
    double dx = static_cast<double>(p1.x) - p2.x;
    double dy = static_cast<double>(p1.y) - p2.y;

    // Calculate squared differences using direct multiplication for efficiency and precision.
    // The sum of squares is also done in double, which has sufficient range and precision
    // for any possible sum of squares derived from `int` coordinates.
    return std::sqrt(dx * dx + dy * dy);
}

int main() {
    // Demonstrate creating Point objects and calculating their distance

    // Test Case 1: Simple integers (3,4,5 triangle)
    Point p1 = {0, 0};
    Point p2 = {3, 4};
    std::cout << "Distance between (" << p1.x << ", " << p1.y << ") and (" << p2.x << ", " << p2.y << "): "
              << std::fixed << std::setprecision(6) << calculateDistance(p1, p2) << std::endl; // Expected: 5.000000

    // Test Case 2: Negative coordinates
    Point p3 = {-1, -1};
    Point p4 = {2, 3};
    std::cout << "Distance between (" << p3.x << ", " << p3.y << ") and (" << p4.x << ", " << p4.y << "): "
              << std::fixed << std::setprecision(6) << calculateDistance(p3, p4) << std::endl; // Expected: sqrt(3^2 + 4^2) = 5.000000

    // Test Case 3: Large differences to test handling of int limits
    // The difference between `INT_MAX` and `INT_MIN` is `4294967295`.
    // This value fits exactly in a `double`. Its square also fits within `double`'s range and precision.
    Point p5 = {std::numeric_limits<int>::max(), 0};
    Point p6 = {std::numeric_limits<int>::min(), 0};
    std::cout << "Distance between (" << p5.x << ", " << p5.y << ") and (" << p6.x << ", " << p6.y << "): "
              << std::fixed << std::setprecision(6) << calculateDistance(p5, p6) << std::endl; // Expected: 4294967295.000000

    // Test Case 4: Zero distance
    Point p7 = {100, 200};
    Point p8 = {100, 200};
    std::cout << "Distance between (" << p7.x << ", " << p7.y << ") and (" << p8.x << ", " << p8.y << "): "
              << std::fixed << std::setprecision(6) << calculateDistance(p7, p8) << std::endl; // Expected: 0.000000

    return 0;
}