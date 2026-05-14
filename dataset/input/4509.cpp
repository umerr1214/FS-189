#include <iostream> // Required for input (std::cin) and output (std::cout) operations.

int main() {
    int number; // Declare an integer variable to store the user's input.

    // Prompt the user to enter an integer.
    std::cout << "Enter an integer: ";
    // Read the integer from the standard input.
    std::cin >> number;

    // Print a header for the multiplication table.
    std::cout << "Multiplication table for " << number << ":\n";

    // Loop from 1 to 10 to generate the multiplication table.
    for (int i = 1; i <= 10; ++i) {
        // Print each line of the multiplication table in a clear format.
        std::cout << number << " x " << i << " = " << (number * i) << "\n";
    }

    return 0; // Indicate that the program executed successfully.
}