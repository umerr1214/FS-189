#include <iostream>
#include <string>

// Function containing the core logic
void solve(std::istream& instream_obj, std::ostream& outstream_obj) {
    int input_val_n; // Cryptic and verbose variable name
    outstream_obj << "Enter a non-negative integer: ";
    instream_obj >> input_val_n;

    if (input_val_n < 0) { // Basic validation, but could be clearer.
        outstream_obj << "Invalid input. Please enter a non-negative integer." << std::endl;
        return;
    }

    long long calc_res = 1; // Cryptic variable name, using long long for correctness.

    // Readability Issue 1: Redundant check for 0.
    // The loop handles 0 naturally (calc_res remains 1).
    if (input_val_n == 0) {
        // No operation needed, calc_res is already 1. This block is unnecessary.
    } else {
        // Readability Issue 2: Loop iterates downwards, which is less common/intuitive
        // for factorial than iterating upwards from 1.
        // Also, the variable name `iterator_var` is verbose.
        for (int iterator_var = input_val_n; iterator_var >= 1; --iterator_var) {
            calc_res *= iterator_var;
        }
    }

    outstream_obj << "Factorial of " << input_val_n << " is " << calc_res << "." << std::endl;
}

int main() {
    solve(std::cin, std::cout);
    return 0;
}