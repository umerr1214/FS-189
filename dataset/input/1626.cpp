#include <iostream>
#include <cmath> // For std::sqrt

class Point {
private:
    int x_; // Private member
    int y_; // Private member

public:
    // Constructor
    Point(int x, int y) : x_(x), y_(y) {}

    // Method to calculate distance to origin
    double getDistanceToOrigin() {
        return std::sqrt(static_cast<double>(x_ * x_) + static_cast<double>(y_ * y_));
    }
};

int main() {
    Point p1(3, 4);
    // Semantic error: Attempting to access private members 'x_' and 'y_' directly from outside the class.
    // This violates C++ access control rules and will cause a compilation error.
    std::cout << "Point coordinates: (" << p1.x_ << ", " << p1.y_ << ")" << std::endl; 
    
    std::cout << "Distance for (3, 4): " << p1.getDistanceToOrigin() << std::endl;

    Point p2(5, 12);
    std::cout << "Distance for (5, 12): " << p2.getDistanceToOrigin() << std::endl;
    
    return 0;
}