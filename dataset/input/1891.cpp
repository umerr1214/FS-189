#include <iostream>

// Q7: Point2D class with private x and y coordinates
// This version has a robustness issue in its default constructor.
class Point2D {
private:
    int x;
    int y;

public:
    // Robustness Issue: Default constructor leaves x and y uninitialized.
    // This can lead to undefined behavior (printing garbage values) if
    // an object is created using this constructor and then printed.
    Point2D() {
        // x and y are not explicitly initialized here.
        // Their values will be whatever was in memory at that location.
    }

    // Parameterized constructor to properly initialize members.
    Point2D(int x_coord, int y_coord) : x(x_coord), y(y_coord) {}

    // Getters for private members (used by operator<<)
    int getX() const { return x; }
    int getY() const { return y; }
};

// Overload the stream insertion operator <<
// This operator itself is logically correct, but it will expose the
// robustness issue of the Point2D class when an uninitialized object is printed.
std::ostream& operator<<(std::ostream& os, const Point2D& p) {
    os << "(" << p.getX() << ", " << p.getY() << ")";
    return os;
}

int main() {
    // Test cases
    Point2D p1(10, 20);
    Point2D p2(-5, 0);
    
    // This object will be created using the default constructor,
    // leaving its x and y members uninitialized.
    Point2D p3; 

    std::cout << "Point p1: " << p1 << std::endl;
    std::cout << "Point p2: " << p2 << std::endl;
    std::cout << "Point p3 (uninitialized): " << p3 << std::endl; // Exposes robustness issue

    return 0;
}