#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision
#include <cmath>   // Required for std::pow if used, though simple multiplication is fine

int main() {
    const double PI = 3.14159;
    double radius;

    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    // Logical Error: Formulas for area and perimeter are swapped
    double area = 2 * PI * radius;           // This is actually the perimeter formula
    double perimeter = PI * radius * radius; // This is actually the area formula

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;

    return 0;
}