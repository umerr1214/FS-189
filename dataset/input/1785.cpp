#include <iostream>
#include <cmath> // Required for M_PI
#include <limits> // For numeric_limits to check double values (though not strictly needed for this problem)

// Ensure M_PI is available. On some compilers/platforms, it might require _USE_MATH_DEFINES.
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Circle {
private:
    double radius;

public:
    // Default constructor: Initializes radius to a safe, non-negative value.
    Circle() : radius(0.0) {}

    // Parameterized constructor: Initializes radius with validation.
    Circle(double r) : radius(0.0) { // Initialize to 0.0 first, then set with validation
        setRadius(r); // Use the setter for validation
    }

    // Public getter for radius
    double getRadius() const {
        return radius;
    }

    // Public setter for radius with validation
    void setRadius(double r) {
        if (r >= 0.0) {
            radius = r;
        } else {
            // As per requirement, radius cannot be set to a negative value.
            // A robust approach is to not change the radius and optionally
            // provide feedback or set to a default valid value (like 0.0).
            // Here, we'll keep the current radius and print a warning.
            // Another valid approach could be `radius = 0.0;`
            std::cerr << "Warning: Attempted to set negative radius (" << r << "). Radius remains " << radius << "." << std::endl;
        }
    }

    // Method to calculate the circle's area
    double calculateArea() const {
        // Use direct multiplication for efficiency and M_PI for precision.
        return M_PI * radius * radius;
    }
};

int main() {
    // Test Case 1: Default constructor
    std::cout << "--- Test Case 1: Default constructor ---" << std::endl;
    Circle c1;
    std::cout << "Initial radius of c1: " << c1.getRadius() << std::endl;
    std::cout << "Area of c1: " << c1.calculateArea() << std::endl;
    std::cout << std::endl;

    // Test Case 2: Constructor with valid radius
    std::cout << "--- Test Case 2: Constructor with valid radius ---" << std::endl;
    Circle c2(5.0);
    std::cout << "Radius of c2: " << c2.getRadius() << std::endl;
    std::cout << "Area of c2: " << c2.calculateArea() << std::endl;
    std::cout << std::endl;

    // Test Case 3: Constructor with invalid (negative) radius
    std::cout << "--- Test Case 3: Constructor with invalid radius ---" << std::endl;
    Circle c3(-2.0); // Should trigger warning and set radius to 0.0
    std::cout << "Radius of c3: " << c3.getRadius() << std::endl;
    std::cout << "Area of c3: " << c3.calculateArea() << std::endl;
    std::cout << std::endl;

    // Test Case 4: Setter with valid radius
    std::cout << "--- Test Case 4: Setter with valid radius ---" << std::endl;
    c1.setRadius(10.0);
    std::cout << "Radius of c1 after setRadius(10.0): " << c1.getRadius() << std::endl;
    std::cout << "Area of c1: " << c1.calculateArea() << std::endl;
    std::cout << std::endl;

    // Test Case 5: Setter with invalid (negative) radius
    std::cout << "--- Test Case 5: Setter with invalid radius ---" << std::endl;
    c2.setRadius(-7.0); // Should trigger warning and keep radius at 5.0
    std::cout << "Radius of c2 after setRadius(-7.0): " << c2.getRadius() << std::endl;
    std::cout << "Area of c2: " << c2.calculateArea() << std::endl;
    std::cout << std::endl;

    // Test Case 6: Setting radius to zero
    std::cout << "--- Test Case 6: Setting radius to zero ---" << std::endl;
    c1.setRadius(0.0);
    std::cout << "Radius of c1: " << c1.getRadius() << std::endl;
    std::cout << "Area of c1: " << c1.calculateArea() << std::endl;
    std::cout << std::endl;

    return 0;
}