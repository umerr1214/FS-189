#include <iostream>
#include <string>
#include <iomanip> // Required for std::fixed and std::setprecision

class Point {
private:
    double x;
    double y;
public:
    // Constructor with default arguments for convenience
    Point(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // Public const getter methods to access private coordinates safely
    double getX() const { return x; }
    double getY() const { return y; }
};

// Overloaded non-member function to print a Point
// Pass by const reference for efficiency and to ensure the Point object is not modified.
void print(const Point& p) {
    // Use std::fixed and std::setprecision for consistent and readable floating-point output.
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Point: (" << p.getX() << ", " << p.getY() << ")" << std::endl;
}

// Overloaded non-member function to print a Point with a custom prefix
// Pass by const reference for efficiency and to ensure the Point and string objects are not modified.
void print(const Point& p, const std::string& prefix) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << prefix << ": (" << p.getX() << ", " << p.getY() << ")" << std::endl;
}

int main() {
    Point p1(10.5, 20.25);
    Point p2(0.123456789, 987654321.123456789);
    Point p3(1.0/3.0, 2.0/3.0);
    Point p4; // Default constructor
    Point p5(-5.0, 15.7);

    print(p1);
    print(p2, "ComplexPoint");
    print(p3, "FractionPoint");
    print(p4, "Origin");
    print(p5);

    return 0;
}