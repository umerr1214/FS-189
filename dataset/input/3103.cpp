#include <iostream>
#include <cmath> // For M_PI

class Circle {
private:
    double radius;

public:
    // Constructor allows any radius, including negative
    Circle(double r) : radius(r) {}

    // getArea is const, but calculation might use a negative radius
    double getArea() const {
        // Area calculation assumes radius * radius is always positive,
        // but if radius was negative, the geometric interpretation is lost.
        // The class doesn't prevent this invalid state.
        return M_PI * radius * radius;
    }

    // resize method allows setting a negative radius without validation
    void resize(double newRadius) {
        radius = newRadius;
    }

    double getRadius() const {
        return radius;
    }
};

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

    // Demonstrate robustness issue: allowing negative radius
    c1.resize(-3.0);
    std::cout << "c1 after resize(-3.0) (Robustness Issue):\n";
    std::cout << "  Radius: " << c1.getRadius() << ", Area: " << c1.getArea() << " (Geometrically incorrect)\n";

    // Const Circle object
    const Circle c2(7.0);
    std::cout << "\nInitial Circle c2 (const):\n";
    std::cout << "  Radius: " << c2.getRadius() << ", Area: " << c2.getArea() << "\n";

    // Attempt to call resize on const object (will cause compile error if uncommented)
    // c2.resize(1.0); // ERROR: 'this' has type 'const Circle', but method is not const

    // Call const method on const object
    std::cout << "c2's area (called on const object): " << c2.getArea() << "\n";

    return 0;
}