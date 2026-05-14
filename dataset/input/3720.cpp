#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    int length_int, width_int; // Semantic error: using int instead of float/double

    std::cout << "Enter the length of the rectangle: ";
    std::cin >> length_int; // Reads floating-point input but truncates decimal part

    std::cout << "Enter the width of the rectangle: ";
    std::cin >> width_int; // Reads floating-point input but truncates decimal part

    // Calculations will use the truncated integer values
    float area = static_cast<float>(length_int) * static_cast<float>(width_int);
    float perimeter = 2 * (static_cast<float>(length_int) + static_cast<float>(width_int));

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;

    return 0;
}