#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision
#include <cmath>   // Required for std::pow if used, though simple multiplication is fine

int main() {
    const double PI = 3.14159;
    double radius;

    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    // Semantic Error: Attempting to modify a const variable
    PI = 3.14; // This line causes a semantic error as PI is declared const

    double area = PI * radius * radius;
    double perimeter = 2 * PI * radius;

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;

    return 0;
}