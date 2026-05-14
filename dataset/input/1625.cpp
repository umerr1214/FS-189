#include <iostream>
#include <cmath> // Included, but sqrt is not used for the distance calculation

class Point {
private:
    int x_;
    int y_;

public:
    // Constructor
    Point(int x, int y) : x_(x), y_(y) {}

    // Method to calculate distance to origin
    double getDistanceToOrigin() {
        // Logical error: Returns the squared Euclidean distance instead of the actual distance.
        return static_cast<double>(x_ * x_ + y_ * y_);
    }
};

int main() {
    Point p1(3, 4);
    std::cout << "Distance for (3, 4): " << p1.getDistanceToOrigin() << std::endl; // Expected: 5.0, Actual: 25.0

    Point p2(5, 12);
    std::cout << "Distance for (5, 12): " << p2.getDistanceToOrigin() << std::endl; // Expected: 13.0, Actual: 169.0
    
    Point p3(0, 0);
    std::cout << "Distance for (0, 0): " << p3.getDistanceToOrigin() << std::endl; // Expected: 0.0, Actual: 0.0

    return 0;
}