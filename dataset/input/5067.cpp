#include <iostream>
#include <limits> // Required for std::numeric_limits
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    double length = 0.0;
    double width = 0.0;

    // Robust input loop for length: ensures numeric and positive input
    while (true) {
        std::cout << "Enter length of the rectangle: ";
        std::cin >> length;

        if (std::cin.fail()) { // Check if input failed (e.g., non-numeric)
            std::cout << "Invalid input. Please enter a numeric value for length." << std::endl;
            std::cin.clear(); // Clear the error flags
            // Discard invalid input from the buffer up to the newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (length <= 0) { // Check for non-positive values
            std::cout << "Length must be a positive value. Please try again." << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear remaining input
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear remaining input
            break; // Valid input, exit loop
        }
    }

    // Robust input loop for width: ensures numeric and positive input
    while (true) {
        std::cout << "Enter width of the rectangle: ";
        std::cin >> width;

        if (std::cin.fail()) { // Check if input failed (e.g., non-numeric)
            std::cout << "Invalid input. Please enter a numeric value for width." << std::endl;
            std::cin.clear(); // Clear the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (width <= 0) { // Check for non-positive values
            std::cout << "Width must be a positive value. Please try again." << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear remaining input
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear remaining input
            break; // Valid input, exit loop
        }
    }

    // Calculate area and perimeter using descriptive variable names
    double area = length * width;
    double perimeter = 2 * (length + width);

    // Print results with clear labels and appropriate formatting for real-world measurements
    std::cout << std::fixed << std::setprecision(2); // Format output to 2 decimal places

    std::cout << "\n--- Rectangle Dimensions ---" << std::endl;
    std::cout << "Length: " << length << std::endl;
    std::cout << "Width: " << width << std::endl;
    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;

    return 0;
}