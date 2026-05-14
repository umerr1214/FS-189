#include <iostream>
#include <string>

// Function containing the core logic
void solve(std::istream& in, std::ostream& out) {
    int num;
    out << "Enter a non-negative integer: ";
    in >> num;

    // Robustness Issue 1: No explicit validation for negative input.
    // If num is negative, the loop below will not execute, and factorial will remain 1,
    // which is an incorrect result for negative numbers (factorial is undefined).
    
    // Robustness Issue 2: Using 'int' for factorial result.
    // This can lead to integer overflow for larger numbers (e.g., > 12!),
    // producing incorrect mathematical results.
    int result_factorial = 1; 

    for (int i = 1; i <= num; ++i) {
        result_factorial *= i;
    }

    out << "Factorial of " << num << " is " << result_factorial << "." << std::endl;
}

int main() {
    solve(std::cin, std::cout);
    return 0;
}