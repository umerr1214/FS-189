#include <iostream>
#include <cmath> // For M_PI and pow

class Circle {
private:
    double radius; // Uninitialized in default constructor

public:
    // Default constructor - radius is NOT initialized to a safe value.
    // This is the robustness issue.
    Circle() {
        // radius is left uninitialized here.
        // A robust design would initialize it, e.g., radius = 0.0;
    }

    // Constructor with initial radius
    Circle(double r) {
        if (r >= 0) {
            radius = r;
        } else {
            // If initial radius is negative, set to 0.0 (a valid state)
            radius = 0.0;
            std::cout << "Warning: Initial radius cannot be negative. Setting to 0.0." << std::endl;
        }
    }

    // Getter for radius
    double getRadius() const {
        return radius;
    }

    // Setter for radius with validation
    void setRadius(double r) {
        if (r >= 0) {
            radius = r;
        } else {
            // If a negative value is attempted, the radius remains unchanged.
            // This is also a robustness issue as it doesn't provide feedback
            // and might leave the object in a state where an update was
            // attempted but failed silently, without setting to a safe default.
            std::cout << "Error: Radius cannot be set to a negative value. Radius remains " << radius << "." << std::endl;
        }
    }

    // Method to calculate area
    double calculateArea() const {
        // If radius was uninitialized by the default constructor,
        // this will result in undefined behavior.
        return M_PI * radius * radius;
    }
};

int main() {
    // Test Case 1: Default constructor without setting radius
    // This demonstrates the robustness issue of uninitialized radius
    std::cout << "--- Test Case 1: Default constructor (uninitialized radius) ---" << std::endl;
    Circle c1;
    // Calling calculateArea() here will use an uninitialized 'radius'
    // leading to undefined behavior. The output will vary.
    std::cout << "Area of c1 (uninitialized radius): " << c1.calculateArea() << std::endl;
    c1.setRadius(5.0);
    std::cout << "Radius of c1 after setRadius(5.0): " << c1.getRadius() << std::endl;
    std::cout << "Area of c1: " << c1.calculateArea() << std::endl;
    std::cout << std::endl;

    // Test Case 2: Constructor with valid radius
    std::cout << "--- Test Case 2: Constructor with valid radius ---" << std::endl;
    Circle c2(10.0);
    std::cout << "Radius of c2: " << c2.getRadius() << std::endl;
    std::cout << "Area of c2: " << c2.calculateArea() << std::endl;
    std::cout << std::endl;

    // Test Case 3: Setter with negative value (demonstrates robustness issue in setter)
    std::cout << "--- Test Case 3: Setter with negative value ---" << std::endl;
    Circle c3(7.0);
    std::cout << "Initial radius of c3: " << c3.getRadius() << std::endl;
    c3.setRadius(-3.0); // Attempt to set negative radius
    std::cout << "Radius of c3 after setRadius(-3.0): " << c3.getRadius() << std::endl; // Should still be 7.0
    std::cout << "Area of c3: " << c3.calculateArea() << std::endl;
    std::cout << std::endl;

    // Test Case 4: Setting radius to zero
    std::cout << "--- Test Case 4: Setting radius to zero ---" << std::endl;
    Circle c4(2.0);
    c4.setRadius(0.0);
    std::cout << "Radius of c4: " << c4.getRadius() << std::endl;
    std::cout << "Area of c4: " << c4.calculateArea() << std::endl;
    std::cout << std::endl;

    return 0;
}