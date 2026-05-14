#include <iostream>

// Function to encapsulate the core logic for testing
void run_multiplication_table_logic() {
    int num = 0; // Initialize to 0 to make behavior predictable on invalid input
    std::cout << "Enter a number to see its multiplication table: ";
    std::cin >> num;

    // Robustness Issue: No input validation for non-numeric input.
    // If the user enters non-numeric input (e.g., "abc"), std::cin fails,
    // 'num' retains its initialized value of 0, and the program proceeds to print
    // the table for 0. The stream's error state is not cleared, which is also
    // a robustness flaw as subsequent reads would also fail.
    // This allows the program to continue with potentially invalid data,
    // leading to unexpected output without informing the user of the error.

    for (int i = 1; i <= 10; ++i) {
        std::cout << num << " x " << i << " = " << (num * i) << std::endl;
    }
}

int main() {
    run_multiplication_table_logic();
    return 0;
}