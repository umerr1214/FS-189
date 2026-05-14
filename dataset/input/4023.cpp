#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision
#include <limits>  // Required for std::numeric_limits

// Helper function to clear the input buffer and error flags
void clear_input_buffer() {
    std::cin.clear(); // Clear the error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input up to the newline
}

int main() {
    double length, width;

    // Prompt and validate length input
    while (true) {
        std::cout << "Enter the length of the rectangle: ";
        std::cin >> length;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a numeric value.\n";
            clear_input_buffer();
        } else if (length <= 0) {
            std::cout << "Length must be a positive number. Please try again.\n";
            clear_input_buffer(); // Clear any potential extra input on the line
        } else {
            break; // Valid input received
        }
    }

    // Prompt and validate width input
    while (true) {
        std::cout << "Enter the width of the rectangle: ";
        std::cin >> width;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a numeric value.\n";
            clear_input_buffer();
        } else if (width <= 0) {
            std::cout << "Width must be a positive number. Please try again.\n";
            clear_input_buffer(); // Clear any potential extra input on the line
        } else {
            break; // Valid input received
        }
    }

    // Calculate area and perimeter
    double area = length * width;
    double perimeter = 2 * (length + width);

    // Display results formatted to two decimal places
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Calculated Area: " << area << std::endl;
    std::cout << "Calculated Perimeter: " << perimeter << std::endl;

    return 0;
}