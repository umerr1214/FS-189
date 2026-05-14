#include <iostream>
#include <cmath> // For M_PI

class Circle {
private:
    double radius;
    // Define PI as a static const member for precision and encapsulation
    static const double PI;

public:
    // Constructor with input validation
    Circle(double r) : radius(0.0) { // Initialize to a safe default
        if (r >= 0) {
            radius = r;
        } else {
            std::cerr << "Warning: Radius cannot be negative. Setting to 0.0.\n";
        }
    }

    // getArea method: const-correct, does not modify object state, uses class's PI
    double getArea() const {
        return PI * radius * radius;
    }

    // resize method: modifies object state, includes input validation
    void resize(double newRadius) {
        if (newRadius >= 0) {
            radius = newRadius;
        } else {
            std::cerr << "Warning: New radius cannot be negative. Radius remains unchanged.\n";
        }
    }

    // getRadius method: const-correct, provides access to private member
    double getRadius() const {
        return radius;
    }
};

// Initialize static const member outside the class definition
const double Circle::PI = M_PI; // Using M_PI for high precision

int main() {
    std::cout.precision(4);
    std::cout << std::fixed;

    // Non-const Circle object
    Circle c1(5.0);
    std::cout << "Initial Circle c1 (non-const):\n";
    std::cout << "  Radius: " << c1.getRadius() << ", Area: " << c1.getArea() << "\n";

    // Call resize on non-const object
    c1.resize(10.0);
    std::cout << "c1 after resize(10.0):\n";
    std::cout << "  Radius: " << c1.getRadius() << ", Area: " << c1.getArea() << "\n";

    // Test resize with invalid input
    std::cout << "Testing resize with negative value:\n";
    c1.resize(-2.0); // Should print a warning and not change radius
    std::cout << "  Radius: " << c1.getRadius() << ", Area: " << c1.getArea() << "\n";

    // Const Circle object
    const Circle c2(7.0);
    std::cout << "\nInitial Circle c2 (const):\n";
    std::cout << "  Radius: " << c2.getRadius() << ", Area: " << c2.getArea() << "\n";

    // Attempt to call resize on const object (this would be a compile-time error)
    // c2.resize(1.0); // Uncommenting this line will cause a compilation error.

    // Call const method on const object
    std::cout << "c2's area (called on const object): " << c2.getArea() << "\n";

    // Test constructor with invalid input
    std::cout << "\nTesting constructor with negative value:\n";
    Circle c3(-4.0);
    std::cout << "  Radius: " << c3.getRadius() << ", Area: " << c3.getArea() << "\n";

    return 0;
}