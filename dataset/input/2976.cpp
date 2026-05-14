#include <iostream>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed and std::setprecision

// Define PI if M_PI is not available (e.g., some compilers without strict C++ standard)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() {
        return M_PI * radius * radius;
    }

    double calculateCircumference() {
        return 2 * M_PI * radius;
    }
};

int main() {
    Circle myCircle(5.0);
    std::cout << std::fixed << std::setprecision(15);
    // Semantic Error: Attempting to directly access a private member 'radius'
    // This violates encapsulation and will result in a compile-time error.
    std::cout << "Radius: " << myCircle.radius << std::endl; 
    std::cout << "Area: " << myCircle.calculateArea() << std::endl;
    std::cout << "Circumference: " << myCircle.calculateCircumference() << std::endl;
    return 0;
}