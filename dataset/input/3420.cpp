#include <iostream>
// #include <cmath> // M_PI is typically defined here or needs explicit definition
#include <iomanip> // For std::fixed, std::setprecision

int main() {
    double radius;
    double area;
    double circumference;

    // Semantic Error: M_PI is defined as an integer (3) instead of a floating-point number (3.14159),
    // violating the problem's requirement for a precise PI value.
    const int M_PI_VAL = 3; 

    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    area = M_PI_VAL * radius * radius;
    circumference = 2 * M_PI_VAL * radius;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Area: " << area << std::endl;
    std::cout << "Circumference: " << circumference << std::endl;

    return 0;
}