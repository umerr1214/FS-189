#include <iostream>
#include <cmath> // Required for pow, though r*r*r is used
#include <iomanip> // Required for std::fixed and std::setprecision

// Semantic Error: PI declared as const int, truncating 3.14159 to 3
const int PI = 3.14159;

// The main function is renamed to _user_main for testing purposes by the driver.
int _user_main() {
    double radius;
    double volume;

    std::cout << "Enter the radius of the sphere: ";
    std::cin >> radius;

    volume = (4.0 / 3.0) * PI * radius * radius * radius;

    std::cout << "The volume of the sphere is: " << std::fixed << std::setprecision(5) << volume << std::endl;

    return 0;
}