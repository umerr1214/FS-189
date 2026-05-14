#include <iostream>

int main() {
    int choice;
    double radius, side, base, height;
    const double PI = 3.14159; // Simplified PI for this example

    while (true) {
        std::cout << "\nArea Calculator Menu:\n";
        std::cout << "1. Circle\n";
        std::cout << "2. Square\n";
        std::cout << "3. Triangle\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice; // Robustness Issue: No input validation for non-numeric input

        // If input fails (e.g., non-numeric), cin will be in a fail state.
        // Without clearing the error and ignoring bad input, this will lead to an infinite loop.
        // The 'a' from input "a\n4" will remain in the buffer, causing cin to fail repeatedly.

        switch (choice) {
            case 1:
                std::cout << "Enter radius of the circle: ";
                std::cin >> radius; // Robustness Issue: No validation for negative radius
                std::cout << "Area of circle: " << PI * radius * radius << std::endl;
                break;
            case 2:
                std::cout << "Enter side length of the square: ";
                std::cin >> side; // Robustness Issue: No validation for negative side
                std::cout << "Area of square: " << side * side << std::endl;
                break;
            case 3:
                std::cout << "Enter base of the triangle: ";
                std::cin >> base; // Robustness Issue: No validation for negative base
                std::cout << "Enter height of the triangle: ";
                std::cin >> height; // Robustness Issue: No validation for negative height
                std::cout << "Area of triangle: " << 0.5 * base * height << std::endl;
                break;
            case 4:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}