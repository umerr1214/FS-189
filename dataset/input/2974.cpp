#include <iostream>
#include <cmath> // For M_PI

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
} // ERROR: Missing semicolon here

int main() {
    Circle myCircle(5.0);
    std::cout << "Area: " << myCircle.calculateArea() << std::endl;
    std::cout << "Circumference: " << myCircle.calculateCircumference() << std::endl;
    return 0;
}