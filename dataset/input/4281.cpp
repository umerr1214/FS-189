#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    float originalNumber; // Clear and descriptive variable name

    std::cout << "Enter a floating-point number: ";
    
    // Attempt to read input and robustly handle potential input errors
    if (!(std::cin >> originalNumber)) {
        std::cerr << "Invalid input. Please enter a valid floating-point number.\n";
        // Clear error flags and ignore the rest of the invalid input in the buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1; // Indicate an error by returning a non-zero status
    }

    // Explicitly cast the floating-point number to an integer using static_cast
    int convertedInteger = static_cast<int>(originalNumber);

    // Calculate the difference between the original and converted numbers
    float difference = originalNumber - convertedInteger;

    // Print both the original and converted numbers, and their difference
    // Using '\n' for newlines is generally more efficient than std::endl
    // as it doesn't force a flush of the output buffer.
    std::cout << "Original number: " << originalNumber << '\n';
    std::cout << "Integer converted number: " << convertedInteger << '\n';
    std::cout << "Difference: " << difference << '\n';

    return 0; // Indicate successful execution
}