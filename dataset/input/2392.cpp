#include <iostream>

class Circle {
public:
    double radius;

    // Default constructor
    Circle() : radius(0.0) {}

    // Parameterized constructor
    Circle(double r) : radius(r) {}

    // Copy constructor
    Circle(const Circle& other) : radius(other.radius) {}

    void printRadius() const {
        std::cout << "Radius: " << radius << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    Circle c1; // Default constructor
    Circle c2(5.5); // Parameterized constructor
    Circle c3 = c2; // Copy constructor

    c1.printRadius();
    c2.printRadius();
    c3.printRadius();

    return 0;
}