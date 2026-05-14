#include <iostream>
#include <cmath> // For M_PI or just use a literal

class Circle {
private:
    double radius;
public:
    // Constructor
    Circle(double r = 0.0) : radius(r) {
        // Basic validation for good measure
        if (radius < 0) {
            radius = 0; // Ensure non-negative radius
        }
    }

    // const member function: Returns the radius
    double getRadius() const {
        return radius;
    }

    // non-const member function: Sets the radius
    void setRadius(double r) {
        if (r >= 0) { // Input validation for robustness
            radius = r;
        } else {
            // Provide a warning and handle invalid input gracefully
            std::cerr << "Warning: Attempted to set a negative radius (" << r << "). Setting to 0 instead." << std::endl;
            radius = 0;
        }
    }

    // Helper const method for demonstration
    double calculateArea() const {
        const double PI = 3.14159265358979323846; // Use a more precise constant
        return PI * radius * radius;
    }
};

int main() {
    // Create a const Circle object
    const Circle const_circle(5.0);

    std::cout << "--- Demonstrating const Circle object ---" << std::endl;
    std::cout << "Const Circle radius: " << const_circle.getRadius() << std::endl;
    std::cout << "Const Circle area: " << const_circle.calculateArea() << std::endl;

    // Attempting to call setRadius() on a const object will result in a compile-time error.
    // Uncommenting the line below would prevent compilation:
    // const_circle.setRadius(6.0);
    std::cout << "Note: Calling setRadius() on a const Circle object is not allowed and would cause a compilation error." << std::endl;
    std::cout << std::endl;

    // Create a non-const Circle object to demonstrate setRadius
    Circle mutable_circle(10.0);
    std::cout << "--- Demonstrating non-const Circle object ---" << std::endl;
    std::cout << "Mutable Circle initial radius: " << mutable_circle.getRadius() << std::endl;
    mutable_circle.setRadius(12.5);
    std::cout << "Mutable Circle radius after setRadius(12.5): " << mutable_circle.getRadius() << std::endl;
    std::cout << "Mutable Circle area: " << mutable_circle.calculateArea() << std::endl;

    // Test setRadius with invalid input (robustness for correct version)
    mutable_circle.setRadius(-4.0);
    std::cout << "Mutable Circle radius after setRadius(-4.0): " << mutable_circle.getRadius() << std::endl; // Should be 0 due to validation
    std::cout << "Mutable Circle area: " << mutable_circle.calculateArea() << std::endl;

    return 0;
}