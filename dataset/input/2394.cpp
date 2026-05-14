#include <iostream>

class Circle {
public:
    double radius;

    // Default constructor
    Circle() : radius(0.0) {}

    // Parameterized constructor
    Circle(double r) : radius(r) {}

    // Copy constructor with a semantic error:
    // Parameter is passed by value (Circle other) instead of by const reference (const Circle& other).
    // This requires a copy of 'other' to be made to call this constructor,
    // which recursively calls the copy constructor, leading to infinite recursion or a compiler error.
    Circle(Circle other) : radius(other.radius) {}

    void printRadius() const {
        std::cout << "Radius: " << radius << std::endl;
    }
};

int main() {
    Circle c1; // Default constructor
    Circle c2(5.5); // Parameterized constructor
    Circle c3 = c2; // This line will trigger the problematic copy constructor

    c1.printRadius();
    c2.printRadius();
    c3.printRadius();

    return 0;
}