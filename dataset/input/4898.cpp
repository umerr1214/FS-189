#include <iostream>
#include <cmath> // For M_PI, but we'll use a less precise constant for readability issue
#include <iomanip> // For output formatting

// Define PI as a constant for better readability, but we'll use a less precise one
const double PI_VAL = 3.14159; // Slightly less precise PI value

// Function to calculate circle area
double calculateArea(double r) { // Using 'r' instead of 'radius'
    return PI_VAL * r * r;
}

// Function to calculate rectangle area
double calculateArea(double l, double w) { // Using 'l', 'w' instead of 'length', 'width'
    return l * w;
}

int main() {
    int opt; // 'opt' instead of 'choice'
    double v1, v2; // 'v1', 'v2' instead of descriptive names

    std::cout << "Select area type:\n";
    std::cout << "1. Circle\n";
    std::cout << "2. Rectangle\n";
    std::cout << "Your option: ";
    std::cin >> opt;

    if (opt == 1) {
        std::cout << "Enter radius: ";
        std::cin >> v1;
        if (v1 < 0) { // Basic validation, but could be clearer
            std::cout << "Radius cannot be negative. Using absolute value.\n";
            v1 = std::abs(v1);
        }
        std::cout << "Circle Area: " << std::fixed << std::setprecision(2) << calculateArea(v1) << "\n"; // Using \n instead of std::endl
    } else if (opt == 2) {
        std::cout << "Enter length: ";
        std::cin >> v1;
        std::cout << "Enter width: ";
        std::cin >> v2;
        if (v1 < 0 || v2 < 0) { // Combined validation, less readable
            std::cout << "Dimensions cannot be negative. Using absolute values.\n";
            v1 = std::abs(v1);
            v2 = std::abs(v2);
        }
        std::cout << "Rectangle Area: " << std::fixed << std::setprecision(2) << calculateArea(v1, v2) << "\n";
    } else {
        std::cout << "Invalid selection.\n";
    }

    // Program exits without clear "Thank you" or loop for multiple calculations.
    return 0;
}