#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision
#include <limits>  // For std::numeric_limits to clear input buffer

int main() {
    float length, width;

    // Prompt for length and validate input
    while (true) {
        std::cout << "Enter the length of the rectangle: ";
        std::cin >> length;

        if (std::cin.fail() || length <= 0) {
            std::cout << "Invalid input. Please enter a positive floating-point number for length.\n";
            std::cin.clear(); // Clear the error flag
            // Discard invalid input from the buffer up to the newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break; // Valid input received, exit loop
        }
    }

    // Prompt for width and validate input
    while (true) {
        std::cout << "Enter the width of the rectangle: ";
        std::cin >> width;

        if (std::cin.fail() || width <= 0) {
            std::cout << "Invalid input. Please enter a positive floating-point number for width.\n";
            std::cin.clear(); // Clear the error flag
            // Discard invalid input from the buffer up to the newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break; // Valid input received, exit loop
        }
    }

    // Calculate area and perimeter using clear, descriptive variable names
    float area = length * width;
    float perimeter = 2 * (length + width); // Efficient and readable perimeter calculation

    // Display results with appropriate labels and formatting
    std::cout << "\n--- Rectangle Properties ---\n";
    std::cout << "Length:    " << std::fixed << std::setprecision(2) << length << std::endl;
    std::cout << "Width:     " << std::fixed << std::setprecision(2) << width << std::endl;
    std::cout << "Area:      " << std::fixed << std::setprecision(2) << area << std::endl;
    std::cout << "Perimeter: " << std::fixed << std::setprecision(2) << perimeter << std::endl;

    return 0;
}