#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int product = 1; // Potential integer overflow if numbers are large
    int number;

    std::cout << "Enter non-zero integers (0 to stop):" << std::endl;

    // This loop does not handle non-integer input gracefully.
    // If a non-integer is entered, std::cin will go into a fail state,
    // stop further input, and the loop will terminate, potentially
    // displaying an incorrect partial product or the initial product of 1.
    while (std::cin >> number) {
        if (number == 0) {
            break; // Stop taking input if 0 is entered
        }
        // No check for potential overflow before multiplication.
        // If product * number exceeds int's max value, it will overflow.
        product *= number;
    }

    std::cout << "Product of non-zero numbers: " << product << std::endl;

    return 0;
}