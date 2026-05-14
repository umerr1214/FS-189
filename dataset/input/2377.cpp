#include <iostream>
#include <cmath>   // For sqrt
#include <iomanip> // For std::fixed, std::setprecision

class Point {
private:
    int x;
    int y;

public:
    // Constructor
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    // Method to set coordinates
    void setCoordinates(int newX, int newY) {
        x = newX;
        y = newY;
    }

    // Method to calculate Euclidean distance from (0,0)
    // Robustness Issue: Intermediate calculation x*x + y*y might overflow 'int'
    // before being cast to double, leading to incorrect results for large coordinates.
    double getDistanceToOrigin() {
        // If x and y are large enough (e.g., > 46340 for 32-bit int), x*x will overflow.
        // The sum x*x + y*y will also overflow if individual terms do, or if their sum exceeds INT_MAX.
        // The result of the overflowed int calculation is then cast to double.
        return std::sqrt(static_cast<double>(x * x + y * y));
    }
};

int main() {
    // Set output precision for double values
    std::cout << std::fixed << std::setprecision(2);

    Point p1;
    p1.setCoordinates(3, 4);
    std::cout << "Distance for (3, 4): " << p1.getDistanceToOrigin() << std::endl;

    Point p2;
    p2.setCoordinates(0, 0);
    std::cout << "Distance for (0, 0): " << p2.getDistanceToOrigin() << std::endl;

    Point p3;
    p3.setCoordinates(-5, 12);
    std::cout << "Distance for (-5, 12): " << p3.getDistanceToOrigin() << std::endl;

    // Test case demonstrating robustness issue: large coordinates causing int overflow
    // For 32-bit signed int, INT_MAX is approx 2.147 billion.
    // 50000 * 50000 = 2,500,000,000, which overflows int.
    // x*x and y*y will become negative due to overflow, leading to sqrt of a negative number (NaN).
    Point p4;
    p4.setCoordinates(50000, 50000);
    std::cout << "Distance for (50000, 50000): " << p4.getDistanceToOrigin() << std::endl;

    return 0;
}