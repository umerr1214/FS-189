#include <iostream>
#include <cmath> // For sqrt and pow
// No comments, less descriptive variable names, redundant calculations, debug output

struct Point {
    int x;
    int y;
};

// This function has readability issues due to less descriptive variable names,
// an efficiency issue by using std::pow instead of direct multiplication for squaring,
// and includes unnecessary debug output.
double calculateDistance(Point ptA, Point ptB) { // Less descriptive parameter names
    // Calculate differences
    double diffX = static_cast<double>(ptA.x - ptB.x); // Unnecessary cast to double immediately, or could cast before subtraction
    double diffY = static_cast<double>(ptA.y - ptB.y);

    // Calculate squares using std::pow, which is less efficient and potentially less precise
    // than direct multiplication for integer-derived values.
    double sqX = std::pow(diffX, 2.0); // Redundant 2.0, just 2 is fine, still inefficient
    double sqY = std::pow(diffY, 2.0);

    // Sum of squares
    double sumOfSq = sqX + sqY; // Could be done in one line

    std::cout << "DEBUG: Intermediate sum of squares: " << sumOfSq << std::endl; // Unnecessary debug output

    // Calculate final distance
    double finalResult = std::sqrt(sumOfSq); // Could be returned directly

    return finalResult;
}

int main() {
    Point p1 = {0, 0};
    Point p2 = {3, 4};
    std::cout.precision(6);
    std::cout << std::fixed << "Distance: " << calculateDistance(p1, p2) << std::endl;

    Point p3 = {-10, -20};
    Point p4 = {20, 10};
    std::cout << std::fixed << "Another Distance: " << calculateDistance(p3, p4) << std::endl;

    Point p5 = {1, 1};
    Point p6 = {1, 1};
    std::cout << std::fixed << "Zero Distance: " << calculateDistance(p5, p6) << std::endl;

    return 0;
}