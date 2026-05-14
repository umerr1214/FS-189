#include <iostream>
#include <limits> // Required for std::numeric_limits

// Function to encapsulate the core logic for testing
void run_multiplication_table_logic() {
    int number;
    std::cout << "Enter an integer to display its multiplication table (1 to 10): ";
    std::cin >> number;

    // Robust input validation: Check if the input operation failed
    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a valid integer." << '\n';
        // Clear error flags on std::cin
        std::cin.clear();
        // Ignore the rest of the invalid input in the buffer up to the newline character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return; // Exit the function gracefully as input was invalid
    }

    // Informative output message before printing the table
    std::cout << "Multiplication table for " << number << ":" << '\n';
    for (int i = 1; i <= 10; ++i) {
        // Efficient output using '\n' (newline character) instead of std::endl
        // to avoid unnecessary buffer flushes on each iteration.
        std::cout << number << " x " << i << " = " << (number * i) << '\n';
    }
}

int main() {
    run_multiplication_table_logic();
    return 0;
}