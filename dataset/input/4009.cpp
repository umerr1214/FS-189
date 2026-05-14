#include <iostream>
#include <cmath> // For std::sqrt

// Define the struct Point
struct Point {
    int x;
    int y;
};

// Function to calculate Euclidean distance with a robustness issue
double calculateDistance(Point p1, Point p2) {
    // Calculate differences in coordinates
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;

    // --- ROBUSTNESS ISSUE: Potential integer overflow ---
    // If dx or dy are large (e.g., > 46340 for 32-bit int), dx*dx or dy*dy will overflow
    // before being used in the double calculation.
    // A 32-bit signed int max value is ~2 * 10^9. 46341 * 46341 = ~2.147 * 10^9.
    int dx_sq = dx * dx;
    int dy_sq = dy * dy;

    // The sum could also overflow if individual squares didn't but are large.
    int sum_sq = dx_sq + dy_sq;

    // The result of the overflowed integer sum is then cast to double, leading to an incorrect distance.
    return std::sqrt(static_cast<double>(sum_sq));
}

int main() {
    // Create two Point objects as per the question's requirement
    Point pA = {0, 0};
    Point pB = {3, 4};

    // Calculate and display the distance
    double dist = calculateDistance(pA, pB);
    std::cout << "Distance between (" << pA.x << "," << pA.y << ") and (" << pB.x << "," << pB.y << ") is: " << dist << std::endl;

    // Example demonstrating the robustness issue (if uncommented and run directly)
    // Point p_large1 = {0, 0};
    // Point p_large2 = {50000, 0}; // dx = 50000, dx*dx = 2,500,000,000 (overflows int)
    // double large_dist = calculateDistance(p_large1, p_large2);
    // std::cout << "Distance between (" << p_large1.x << "," << p_large1.y << ") and (" << p_large2.x << "," << p_large2.y << ") is: " << large_dist << std::endl;

    return 0;
}