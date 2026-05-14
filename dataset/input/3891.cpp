#include <iostream>
#include <string>    // Required for std::string and std::getline
#include <sstream>   // Required for std::stringstream

int main() {
    double s1, s2, s3;
    std::string line;

    std::cout << "Enter the three side lengths (e.g., 3.0 4.0 5.0): ";
    std::getline(std::cin, line); // Read the entire line of input

    std::stringstream ss(line); // Use stringstream to parse the numbers

    // Check if three numeric values were successfully extracted
    if (!(ss >> s1 >> s2 >> s3)) {
        std::cout << "Invalid input: Please enter three numeric values.\n";
        return 1;
    }

    // Additional check for extra non-whitespace characters after the three numbers
    // This makes input parsing more robust
    char remaining_char;
    if (ss >> remaining_char) {
        std::cout << "Invalid input: Please enter exactly three numeric values.\n";
        return 1;
    }

    // Check for positive side lengths
    if (s1 <= 0 || s2 <= 0 || s3 <= 0) {
        std::cout << "Invalid triangle: Side lengths must be positive.\n";
        return 1;
    }

    // Check for invalid triangle conditions (sum of any two sides must be greater than the third)
    // Using explicit checks for clarity
    if (s1 + s2 <= s3 || s1 + s3 <= s2 || s2 + s3 <= s1) {
        std::cout << "Invalid triangle: The sum of any two sides must be greater than the third.\n";
    } else {
        // Determine triangle type using concise and efficient logic
        if (s1 == s2 && s2 == s3) {
            std::cout << "This is an equilateral triangle.\n";
        } else if (s1 == s2 || s1 == s3 || s2 == s3) {
            std::cout << "This is an isosceles triangle.\n";
        } else {
            std::cout << "This is a scalene triangle.\n";
        }
    }

    return 0;
}