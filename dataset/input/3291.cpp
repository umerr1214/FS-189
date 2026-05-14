#include <iostream>
#include <limits> // Required for std::numeric_limits
#include <cmath>  // Required for M_PI

// Define M_PI if it's not available (e.g., on some compilers without _USE_MATH_DEFINES)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    int choice;
    double radius, side, base, height;
    const double PI = M_PI; // Use a high-precision PI constant

    while (true) {
        std::cout << "\n--- Area Calculator Menu ---\n";
        std::cout << "1. Calculate Area of a Circle\n";
        std::cout << "2. Calculate Area of a Square\n";
        std::cout << "3. Calculate Area of a Triangle\n";
        std::cout << "4. Exit Program\n";
        std::cout << "----------------------------\n";
        std::cout << "Enter your choice (1-4): ";

        std::cin >> choice;

        // Input validation for menu choice: handles non-numeric input
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear(); // Clear the error flag
            // Discard invalid input from the buffer up to the newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; // Ask for input again
        }

        switch (choice) {
            case 1:
                std::cout << "Enter the radius of the circle: ";
                // Input validation loop for radius: ensures positive numeric input
                while (!(std::cin >> radius) || radius <= 0) {
                    std::cout << "Invalid input. Please enter a positive number for radius: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cout << "Area of the circle: " << PI * radius * radius << std::endl;
                break;
            case 2:
                std::cout << "Enter the side length of the square: ";
                // Input validation loop for side: ensures positive numeric input
                while (!(std::cin >> side) || side <= 0) {
                    std::cout << "Invalid input. Please enter a positive number for side length: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cout << "Area of the square: " << side * side << std::endl;
                break;
            case 3:
                std::cout << "Enter the base of the triangle: ";
                // Input validation loop for base: ensures positive numeric input
                while (!(std::cin >> base) || base <= 0) {
                    std::cout << "Invalid input. Please enter a positive number for base: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cout << "Enter the height of the triangle: ";
                // Input validation loop for height: ensures positive numeric input
                while (!(std::cin >> height) || height <= 0) {
                    std::cout << "Invalid input. Please enter a positive number for height: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cout << "Area of the triangle: " << 0.5 * base * height << std::endl;
                break;
            case 4:
                std::cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }
    return 0;
}