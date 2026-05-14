#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    const double PI = 3.14159;
    double radius;
    double area;

    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    // Logical Error: Calculating circumference (2 * PI * radius) instead of area (PI * radius * radius)
    area = 2 * PI * radius;

    // Print the area, formatted to 5 decimal places
    std::cout << "The area of the circle is: " << std::fixed << std::setprecision(5) << area << std::endl;

    return 0;
}