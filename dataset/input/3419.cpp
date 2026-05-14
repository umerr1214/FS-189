#include <iostream>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed, std::setprecision

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

    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    // Logical Error: Area calculation is incorrect (multiplied by 2)
    area = 2 * M_PI_VAL * radius * radius; // Should be M_PI_VAL * radius * radius
    circumference = 2 * M_PI_VAL * radius;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Area: " << area << std::endl;
    std::cout << "Circumference: " << circumference << std::endl;

    return 0;
}