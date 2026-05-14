#include <iostream>
#include <limits> // Required for numeric_limits

int main() {
    double length;
    double width;

    // Prompt user for length with input validation
    while (true) {
        std::cout << "Please enter the length of the rectangle (a positive number): ";
        std::cin >> length;

        if (std::cin.fail() || length <= 0) {
            std::cout << "Invalid input. Please enter a positive number for length.\n";
            std::cin.clear(); // Clear error flags
            // Ignore remaining characters in the input buffer up to the newline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break; // Valid input, exit loop
        }
    }

    // Prompt user for width with input validation
    while (true) {
        std::cout << "Please enter the width of the rectangle (a positive number): ";
        std::cin >> width;

        if (std::cin.fail() || width <= 0) {
            std::cout << "Invalid input. Please enter a positive number for width.\n";
            std::cin.clear(); // Clear error flags
            // Ignore remaining characters in the input buffer up to the newline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break; // Valid input, exit loop
        }
    }

    // Calculate area and perimeter using meaningful variable names and double precision
    double area = length * width;
    double perimeter = 2 * (length + width);

    // Display results clearly
    std::cout << "\n--- Rectangle Dimensions ---" << std::endl;
    std::cout << "Length:    " << length << std::endl;
    std::cout << "Width:     " << width << std::endl;
    std::cout << "Area:      " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;

    return 0;
}