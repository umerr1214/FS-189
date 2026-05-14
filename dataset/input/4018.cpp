#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    double length, width;

    std::cout << "Enter length: " // Syntax Error: Missing semicolon here
    std::cin >> length;

    std::cout << "Enter width: ";
    std::cin >> width;

    double area = length * width;
    double perimeter = 2 * (length + width);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;

    return 0;
}