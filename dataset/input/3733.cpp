#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int number = 0; // Initialize to 0 to make output predictable on input failure
    std::cout << "Please enter an integer: ";
    std::cin >> number; // No error checking here

    // If std::cin fails (e.g., non-numeric input), 'number' retains its initialized value of 0.
    // The program will then incorrectly classify the input as zero.
    // This demonstrates a robustness issue due to lack of input validation.

    if (number > 0) {
        std::cout << "The number is positive." << std::endl;
    } else if (number < 0) {
        std::cout << "The number is negative." << std::endl;
    } else { // This branch is taken if number is 0 (valid input) or if input failed and 'number' is still 0.
        std::cout << "The number is zero." << std::endl;
    }

    return 0;
}