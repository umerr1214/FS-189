#include <iostream>
#include <cmath> // For std::sqrt

// Define the struct Point
struct Point {
    int x;
    int y;
};

// Function to calculate Euclidean distance (Correct Version)
// Uses const references for efficiency and correctness, and avoids intermediate integer overflow.
double calculateDistance(const Point& p1, const Point& p2) {
    // Calculate differences in coordinates, casting to double early to prevent overflow
    // and ensure floating-point arithmetic for squaring.
    double dx = static_cast<double>(p1.x - p2.x);
    double dy = static_cast<double>(p1.y - p2.y);

    // Calculate the sum of squares of differences.
    // Using dx*dx is generally more efficient and clearer than std::pow(dx, 2) for squaring.
    double distanceSquared = (dx * dx) + (dy * dy);

    // Return the square root of the sum of squares.
    return std::sqrt(distanceSquared);
}

int main() {
    // Create two Point objects as per the question's requirement
    Point pA = {0, 0};
    Point pB = {3, 4};

    // Calculate and display the distance
    double dist = calculateDistance(pA, pB);
    std::cout << "Distance between (" << pA.x << "," << pA.y << ") and (" << pB.x << "," << pB.y << ") is: " << dist << std::endl;

    // Additional test cases for demonstration
    Point pC = {1, 2};
    Point pD = {4, 6};
    std::cout << "Distance between (" << pC.x << "," << pC.y << ") and (" << pD.x << "," << pD.y << ") is: " << calculateDistance(pC, pD) << std::endl;

    Point pE = {-1, -1};
    Point pF = {2, 3};
    std::cout << "Distance between (" << pE.x << "," << pE.y << ") and (" << pF.x << "," << pF.y << ") is: " << calculateDistance(pE, pF) << std::endl;

    // Test case for large coordinates to confirm robustness
    Point p_large1 = {0, 0};
    Point p_large2 = {50000, 0};
    std::cout << "Distance between (" << p_large1.x << "," << p_large1.y << ") and (" << p_large2.x << "," << p_large2.y << ") is: " << calculateDistance(p_large1, p_large2) << std::endl;

    return 0;
}