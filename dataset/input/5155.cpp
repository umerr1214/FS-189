#include <iostream>
#include <string> // For std::to_string
#include <limits> // Required for std::numeric_limits

int main() {
    int num1 = 0; // Initialize to 0 to make behavior predictable for invalid input
    int num2 = 0; // If input fails, they will retain these values

    std::cout << "Enter the first integer: ";
    std::cin >> num1;

    // No robust input validation here. If non-integer input is given,
    // std::cin will enter a fail state, and num1 will retain its initialized value (0).
    // The error flags are not cleared, and the input buffer is not flushed.

    std::cout << "Enter the second integer: ";
    std::cin >> num2;

    // If std::cin was already in a fail state from the first input,
    // this second extraction will also fail, and num2 will retain its initialized value (0).
    // The program proceeds without handling the invalid input.

    std::string result = (num1 > num2) ? "The first integer (" + std::to_string(num1) + ") is larger." :
                         (num2 > num1) ? "The second integer (" + std::to_string(num2) + ") is larger." :
                         "The two integers are equal.";

    std::cout << result << std::endl;

    return 0;
}