#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    float length, width;

    std::cout << "Enter the length of the rectangle: ";
    std::cin >> length;

    std::cout << "Enter the width of the rectangle: ";
    std::cin >> width;

    float area = length * width;
    float perimeter = length + width; // Logical error: should be 2 * (length + width)

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl; // This will be incorrect

    return 0;
}