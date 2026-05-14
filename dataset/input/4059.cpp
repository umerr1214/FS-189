#include <iostream>
#include <limits> // Required for numeric_limits

int main() {
    int num;
    long long factorial = 1; // Use long long to handle larger factorials

    // Loop for robust input validation
    while (true) {
        std::cout << "Enter a non-negative integer: ";
        if (!(std::cin >> num)) {
            // Handle non-numeric input
            std::cout << "Error: Invalid input. Please enter an integer." << std::endl;
            std::cin.clear(); // Clear the error flag
            // Discard invalid input from the buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (num < 0) {
            // Handle negative input
            std::cout << "Error: Please enter a non-negative integer." << std::endl;
        } else if (num > 20) {
            // Handle potential overflow for long long factorials
            // 20! is the largest factorial that fits in a signed long long
            std::cout << "Error: Factorial of numbers greater than 20 can cause overflow with standard long long. Please enter a number between 0 and 20." << std::endl;
        }
        else {
            // Valid input received, break the loop
            break;
        }
    }

    // Calculate factorial using a for loop
    if (num == 0 || num == 1) {
        factorial = 1; // Base cases for factorial
    } else {
        for (int i = 2; i <= num; ++i) {
            factorial *= i;
        }
    }

    std::cout << "Factorial of " << num << " = " << factorial << std::endl;

    return 0;
}