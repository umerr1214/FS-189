#include <iostream>
#include <iomanip>

int main() {
    float l, w; // Poorly chosen, non-descriptive variable names

    std::cout << "Enter the length of the rectangle: ";
    std::cin >> l;

    std::cout << "Enter the width of the rectangle: ";
    std::cin >> w;

    // Calculations using non-descriptive variables
    float a = l * w; // 'a' is not clear (area)
    float p = l + w + l + w; // Less efficient and less readable than 2 * (l + w)

    std::cout << "\n--- Calculation Results ---\n";
    std::cout << "Area: " << std::fixed << std::setprecision(2) << a << std::endl;
    std::cout << "Perimeter: " << std::fixed << std::setprecision(2) << p << std::endl;

    return 0;
}