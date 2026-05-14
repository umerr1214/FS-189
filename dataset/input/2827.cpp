#include <iostream>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed, std::setprecision

class Circle {
private:
    double radius;
public:
    // Default constructor: sets radius to 1.0
    Circle() : radius(1.0) {}

    // Overloaded constructor: takes a double argument for radius
    // This constructor does NOT validate if the radius is positive,
    // allowing an invalid physical state (e.g., negative radius).
    Circle(double r) : radius(r) {}

    // Method to calculate area
    // Uses the stored radius directly, even if it's negative.
    // The area calculation (r*r) will still be positive,
    // but the object's radius property might be physically meaningless.
    double calculateArea() const {
        return M_PI * radius * radius;
    }

    // Getter for radius for inspection
    double getRadius() const {
        return radius;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(5);

    // Test Case 1: Default circle
    Circle c1;
    std::cout << "Circle 1 (default, radius=" << c1.getRadius() << "): Area = " << c1.calculateArea() << std::endl;

    // Test Case 2: Positive radius
    Circle c2(5.0);
    std::cout << "Circle 2 (radius=" << c2.getRadius() << "): Area = " << c2.calculateArea() << std::endl;

    // Test Case 3: Zero radius
    Circle c3(0.0);
    std::cout << "Circle 3 (radius=" << c3.getRadius() << "): Area = " << c3.calculateArea() << std::endl;

    // Test Case 4: Another positive radius
    Circle c4(2.5);
    std::cout << "Circle 4 (radius=" << c4.getRadius() << "): Area = " << c4.calculateArea() << std::endl;

    // Test Case 5: Robustness Issue - Negative radius
    // The class allows a negative radius (-3.0), which is physically invalid for a circle.
    // While calculateArea() yields a positive result, the object state itself is not robustly handled.
    Circle c5(-3.0);
    std::cout << "Circle 5 (radius=" << c5.getRadius() << "): Area = " << c5.calculateArea() << std::endl;

    return 0;
}