#include <iostream>

class Circle {
private:
    double radius;
public:
    Circle(double r = 0.0) : radius(r) {}

    double getRadius() const {
        return radius;
    }

    // Robustness issue: Allows negative radius without validation
    void setRadius(double r) {
        radius = r; // No check for r >= 0
    }

    // A const method for context
    double calculateArea() const {
        // For simplicity, using a fixed PI value
        return 3.14159 * radius * radius;
    }
};

int main() {
    // Demonstrate const Circle object
    const Circle const_circle(5.0);
    std::cout << "--- Demonstrating const Circle methods ---" << std::endl;
    std::cout << "Const Circle radius: " << const_circle.getRadius() << std::endl;
    std::cout << "Const Circle area: " << const_circle.calculateArea() << std::endl;
    // const_circle.setRadius(6.0); // This would cause a compile-time error, as expected.
    std::cout << "Attempting to call setRadius() on const_circle would fail compilation." << std::endl;
    std::cout << std::endl;

    // Demonstrate robustness issue with a non-const Circle
    Circle mutable_circle(10.0);
    std::cout << "--- Demonstrating Robustness Issue ---" << std::endl;
    std::cout << "Initial mutable Circle radius: " << mutable_circle.getRadius() << std::endl;

    // Setting a conceptually invalid radius (negative)
    mutable_circle.setRadius(-3.0);
    std::cout << "Mutable Circle radius after setting -3.0: " << mutable_circle.getRadius() << std::endl;
    std::cout << "Mutable Circle area with negative radius: " << mutable_circle.calculateArea() << std::endl; // Area will be calculated as if radius is 3.0 (squared), but semantically incorrect.
    std::cout << "This program allows a negative radius, which is geometrically invalid." << std::endl;

    return 0;
}