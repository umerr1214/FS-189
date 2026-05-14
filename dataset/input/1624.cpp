#include <iostream>
#include <cmath> // For std::sqrt

class Point {
private:
    int x_;
    int y_;

public:
    // Constructor
    Point(int x, int y) : x_(x), y_(y) {}

    // Method to calculate distance to origin
    double getDistanceToOrigin() {
        return std::sqrt(static_cast<double>(x_ * x_) + static_cast<double>(y_ * y_)) // Missing semicolon here
    }
};

int main() {
    Point p1(3, 4);
    std::cout << "Distance for (3, 4): " << p1.getDistanceToOrigin() << std::endl;

    Point p2(5, 12);
    std::cout << "Distance for (5, 12): " << p2.getDistanceToOrigin() << std::endl;
    
    return 0;
}