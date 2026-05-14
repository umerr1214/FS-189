#include <iostream> // Required for input/output operations
#include <limits>   // Required for std::numeric_limits to clear input buffer

// Function to swap two integer values by reference
// This is the standard, most readable, and generally most efficient way for modern compilers.
void swapValues(int& a, int& b) {
    int temp = a; // Use a temporary variable to hold one value
    a = b;        // Assign the second value to the first
    b = temp;     // Assign the stored first value to the second
}

int main() {
    int num1, num2; // Declare two integer variables

    // Prompt user for the first integer and validate input
    std::cout << "Enter the first integer: ";
    while (!(std::cin >> num1)) { // Loop until valid integer input is received
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear(); // Clear the error flags (e.g., failbit)
        // Discard invalid input from the buffer up to the newline character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Prompt user for the second integer and validate input
    std::cout << "Enter the second integer: ";
    while (!(std::cin >> num2)) { // Loop until valid integer input is received
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear(); // Clear the error flags
        // Discard invalid input from the buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Display values before swapping
    std::cout << "Before swapping: a = " << num1 << ", b = " << num2 << std::endl;

    // Call the swapValues function to swap the values of num1 and num2
    swapValues(num1, num2);

    // Display values after swapping
    std::cout << "After swapping: a = " << num1 << ", b = " << num2 << std::endl;

    return 0; // Indicate successful execution
}