#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    // Semantic Error: Using int for length and width instead of floating-point types.
    // This causes truncation of decimal inputs, violating the requirement to handle floating-point numbers.
    int length, width; 

    std::cout << "Enter length: ";
    std::cin >> length;

    std::cout << "Enter width: ";
    std::cin >> width;

    // Calculations will use integer arithmetic based on the truncated inputs.
    double area = static_cast<double>(length) * static_cast<double>(width);
    double perimeter = 2 * (static_cast<double>(length) + static_cast<double>(width));

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;

    return 0;
}