#include <iostream>

class Circle {
public:
    double radius;

    // Default constructor
    Circle() : radius(0.0) {}

    // Parameterized constructor with a logical error
    // It always sets radius to 0.0, ignoring the input 'r'
    Circle(double r) : radius(0.0) {
        // Expected: radius(r)
    }

    // Copy constructor
    Circle(const Circle& other) : radius(other.radius) {}

    void printRadius() const {
        std::cout << "Radius: " << radius << std::endl;
    }
};

int main() {
    Circle c1; // Default: radius = 0.0
    Circle c2(5.5); // Parameterized: radius = 0.0 (LOGICAL ERROR)
    Circle c3 = c2; // Copy: radius = 0.0 (copied from c2, which is 0.0)

    c1.printRadius(); // Expected: Radius: 0.0, Actual: Radius: 0.0
    c2.printRadius(); // Expected: Radius: 5.5, Actual: Radius: 0.0
    c3.printRadius(); // Expected: Radius: 5.5, Actual: Radius: 0.0

    return 0;
}