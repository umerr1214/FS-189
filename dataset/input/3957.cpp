#include <iostream>
#include <numeric> // For std::gcd in C++17, but we implement our own.

// Function to calculate the Greatest Common Divisor (GCD) of two positive integers
// using the Euclidean algorithm. Both parameters are passed by value.
// Precondition: a and b must be positive integers.
int findGCD(int a, int b) {
    // The Euclidean algorithm works by repeatedly replacing the larger number
    // with the remainder of the division of the two numbers until one number becomes zero.
    // The non-zero number is then the GCD.
    while (b != 0) {
        int remainder = a % b; // Calculate the remainder
        a = b;                 // Assign the current 'b' to 'a'
        b = remainder;         // Assign the remainder to 'b'
    }
    return a; // When 'b' is 0, 'a' holds the GCD
}

int main() {
    int num1, num2;

    // Input validation loop for the first positive integer
    while (true) {
        std::cout << "Enter the first positive integer: ";
        std::cin >> num1;
        if (std::cin.fail() || num1 <= 0) {
            std::cout << "Invalid input. Please enter a positive integer." << std::endl;
            std::cin.clear(); // Clear error flags
            // Ignore remaining characters in the input buffer up to the newline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break; // Valid input, exit loop
        }
    }

    // Input validation loop for the second positive integer
    while (true) {
        std::cout << "Enter the second positive integer: ";
        std::cin >> num2;
        if (std::cin.fail() || num2 <= 0) {
            std::cout << "Invalid input. Please enter a positive integer." << std::endl;
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break; // Valid input, exit loop
        }
    }

    // Calculate GCD using the findGCD function
    int result = findGCD(num1, num2);

    // Display the result
    std::cout << "The Greatest Common Divisor (GCD) of " << num1 << " and " << num2 << " is " << result << "." << std::endl;

    return 0;
}