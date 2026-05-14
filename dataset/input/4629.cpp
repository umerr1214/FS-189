#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int n;
    long long sum = 0; // Use long long to prevent overflow for large n

    // Prompt user for input
    std::cout << "Enter a positive integer n: ";

    // Input validation loop:
    // Continues to prompt until a valid positive integer is entered.
    // Handles non-integer input (cin.fail()) and non-positive integers (n <= 0).
    while (!(std::cin >> n) || n <= 0) {
        std::cout << "Invalid input. Please enter a positive integer: ";
        std::cin.clear(); // Clear the error flag on cin
        // Ignore the rest of the line to prevent an infinite loop if bad input remains
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Calculate sum using a for loop as required
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    // Display the result
    std::cout << "The sum of natural numbers from 1 to " << n << " is: " << sum << std::endl;

    return 0;
}