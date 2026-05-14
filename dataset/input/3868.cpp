#include <iostream>

int main() {
    double length, width;

    std::cout << "Enter length: ";
    std::cin >> length;

    std::cout << "Enter width: ";
    std::cin >> width;

    double area = length * width;
    double perimeter = 2 * (length + width);

    std::cout << "Area: " << area << std::endl // Missing semicolon here
    std::cout << "Perimeter: " << perimeter << std::endl;

    return 0;
}