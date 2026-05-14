#include <iostream>
#include <cmath>   // For std::hypot, std::sqrt
#include <iomanip> // For std::fixed, std::setprecision

class Point {
private:
    int x;
    int y;

public:
    // Constructor with default arguments for convenience
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    // Public method to modify coordinates
    void setCoordinates(int newX, int newY) {
        x = newX;
        y = newY;
    }

    // Public method to calculate Euclidean distance from (0,0)
    // Uses std::hypot for robust and precise calculation, avoiding intermediate overflow issues.
    double getDistanceToOrigin() const {
        // std::hypot(x, y) is robust against overflow/underflow compared to sqrt(x*x + y*y)
        // by scaling the inputs if they are very large or very small.
        return std::hypot(static_cast<double>(x), static_cast<double>(y));
    }
};

int main() {
    // Set output precision for double values
    std::cout << std::fixed << std::setprecision(2);

    Point p1;
    p1.setCoordinates(3, 4);
    std::cout << "Distance for (3, 4): " << p1.getDistanceToOrigin() << std::endl;

    Point p2(0, 0); // Using constructor
    std::cout << "Distance for (0, 0): " << p2.getDistanceToOrigin() << std::endl;

    Point p3(-5, 12); // Using constructor
    std::cout << "Distance for (-5, 12): " << p3.getDistanceToOrigin() << std::endl;

    // Test with large coordinates to ensure robustness (even though hypot handles it)
    Point p4;
    p4.setCoordinates(50000, 50000);
    std::cout << "Distance for (50000, 50000): " << p4.getDistanceToOrigin() << std::endl;

    return 0;
}