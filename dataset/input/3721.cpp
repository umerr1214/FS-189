#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    float length, width;

    std::cout << "Enter the length of the rectangle: ";
    std::cin >> length; // No error checking. If input fails, 'length' is uninitialized.

    std::cout << "Enter the width of the rectangle: ";
    std::cin >> width; // If previous input failed, std::cin is in a fail state, this will also fail.
                       // 'width' is uninitialized.

    // Calculations will proceed using potentially uninitialized 'length' and 'width'.
    // This leads to undefined behavior. For predictable testing, we assume these
    // might default to 0.0 or garbage that results in 0.0 in some environments.
    float area = length * width;
    float perimeter = 2 * (length + width);

    std::cout << "\n--- Calculation Results ---\n";
    std::cout << "Area: " << std::fixed << std::setprecision(2) << area << std::endl;
    std::cout << "Perimeter: " << std::fixed << std::setprecision(2) << perimeter << std::endl;

    return 0;
}