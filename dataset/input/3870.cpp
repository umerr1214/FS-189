#include <iostream>
#include <cstdio> // For scanf

int main() {
    double length, width;

    std::cout << "Enter length: ";
    // Semantic error: Using %d for double. This will lead to undefined behavior
    // or incorrect values being read into length and width.
    scanf("%d", &length); 

    std::cout << "Enter width: ";
    scanf("%d", &width);

    double area = length * width;
    double perimeter = 2 * (length + width);

    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;

    return 0;
}