#include <iostream>
#include <cmath> // For M_PI

// Define M_PI if not defined (e.g., on MSVC without specific flags)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Circle {
public:
    double radius;

    // Default constructor - Readability/Efficiency Issue: not using initializer list
    Circle() {
        this->radius = 0.0; // Explicitly assigns, less efficient than initializer list for complex types
    }

    // Parameterized constructor - Readability/Efficiency Issue: not using initializer list
    Circle(double r) {
        this->radius = r; // Explicitly assigns, less efficient than initializer list
    }

    // Copy constructor - Readability/Efficiency Issue: not using initializer list
    Circle(const Circle& other) {
        this->radius = other.radius; // Explicitly assigns, less efficient than initializer list
    }

    // Getter for radius - Readability Issue: unnecessary 'this->' usage
    double getRadius() const {
        return this->radius;
    }

    double getArea() const {
        return M_PI * this->radius * this->radius;
    }
};

int main() {
    std::cout.precision(10); // Set precision for output
    std::cout << std::fixed;

    // Test default constructor
    Circle c1;
    std::cout << "Circle c1 (default): Radius = " << c1.getRadius() << ", Area = " << c1.getArea() << std::endl;

    // Test parameterized constructor
    Circle c2(5.0);
    std::cout << "Circle c2 (param 5.0): Radius = " << c2.getRadius() << ", Area = " << c2.getArea() << std::endl;

    // Test copy constructor
    Circle c3 = c2;
    std::cout << "Circle c3 (copy of c2): Radius = " << c3.getRadius() << ", Area = " << c3.getArea() << std::endl;

    Circle c4(10.0);
    std::cout << "Circle c4 (param 10.0): Radius = " << c4.getRadius() << ", Area = " << c4.getArea() << std::endl;

    return 0;
}