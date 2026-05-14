#include <iostream>

int main() {
    double length, width;

    std::cout << "Enter length: ";
    std::cin >> length;

    std::cout << "Enter width: ";
    std::cin >> width;

    // Logical error: Area should be length * width
    double area = length + width; 
    // Logical error: Perimeter should be 2 * (length + width)
    double perimeter = length * width; 

    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;

    return 0;
}