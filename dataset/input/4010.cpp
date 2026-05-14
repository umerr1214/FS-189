#include <iostream>
#include <cmath> // For std::sqrt and std::pow

// Define the struct Point
struct Point {
    int x;
    int y;
};

// Function to calculate Euclidean distance with readability/efficiency issues
double calculateDistance(Point p1, Point p2) { // --- EFFICIENCY ISSUE: Pass by value for struct ---
                                             // Passing structs by value can incur copy overhead.
                                             // Using 'const Point&' is generally more efficient.

    // Calculate differences in coordinates, casting to double
    double dx = static_cast<double>(p1.x - p2.x);
    double dy = static_cast<double>(p1.y - p2.y);

    // --- EFFICIENCY ISSUE: Using std::pow for squaring ---
    // std::pow is a general-purpose power function (often implemented for floating-point exponents)
    // and is typically less efficient than direct multiplication (dx * dx) for integer powers like 2.
    double distanceSquared = std::pow(dx, 2) + std::pow(dy, 2);

    return std::sqrt(distanceSquared);
}

int main() {
    // Create two Point objects as per the question's requirement
    Point pA = {0, 0};
    Point pB = {3, 4};

    // Calculate and display the distance
    double dist = calculateDistance(pA, pB);
    std::cout << "Distance between (" << pA.x << "," << pA.y << ") and (" << pB.x << "," << pB.y << ") is: " << dist << std::endl;

    Point pC = {1, 2};
    Point pD = {4, 6};
    std::cout << "Distance between (" << pC.x << "," << pC.y << ") and (" << pD.x << "," << pD.y << ") is: " << calculateDistance(pC, pD) << std::endl;

    return 0;
}