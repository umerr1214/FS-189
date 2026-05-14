#include <iostream>
#include <cmath> // For M_PI

int main() {
    double radius;
    double area;
    double circumference;

    // Define M_PI if not available
#ifndef M_PI
    const double M_PI_VAL = 3.14159;
#else
    const double M_PI_VAL = M_PI; // Use system M_PI
#endif

    std::cout << "Enter the radius of the circle: " // Syntax Error: Missing semicolon
    std::cin >> radius;

    area = M_PI_VAL * radius * radius;
    circumference = 2 * M_PI_VAL * radius;

    std::cout << "Area: " << area << std::endl;
    std::cout << "Circumference: " << circumference << std::endl;

    return 0;
}