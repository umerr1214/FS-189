#include <iostream> // Required for input/output operations (std::cin, std::cout, std::endl)
#include <limits>   // Required for std::numeric_limits, used in robust input handling

int main() {
    long long product = 1; // Initialize product to 1. Using 'long long' to safely handle large products and prevent overflow.
    int number;            // Variable to store each integer entered by the user.

    std::cout << "Enter non-zero integers (0 to stop):" << std::endl;

    // Loop to continuously read integers. The loop continues as long as input is successful.
    while (std::cin >> number) {
        if (number == 0) {
            break; // If the user enters 0, stop the input loop as it's the sentinel value.
        }
        product *= number; // Multiply the current product by the valid non-zero number.
    }

    // After the loop, check if the input stream failed due to non-integer input.
    // If it failed and it's not the end-of-file, clear the error flag and
    // ignore the rest of the current line to allow the program to continue cleanly.
    if (std::cin.fail() && !std::cin.eof()) {
        std::cin.clear(); // Clear the error flags on std::cin.
        // Ignore any remaining characters in the input buffer up to the newline character.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Display the final calculated product of all non-zero numbers entered.
    std::cout << "Product of non-zero numbers: " << product << std::endl;

    return 0; // Indicate that the program executed successfully.
}