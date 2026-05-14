#include <iostream>
#include <limits> // Included for clarity, though not strictly needed for the semantic error itself

int main() {
    int num;
    int factorial = 1; // Semantic Error: Using 'int' for factorial. This type can easily overflow for larger numbers (e.g., 13!).

    std::cout << "Enter a non-negative integer: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
    } else {
        for (int i = 1; i <= num; ++i) {
            // For numbers like 13 or higher, 'factorial' will exceed INT_MAX,
            // leading to integer overflow and undefined behavior.
            factorial *= i;
        }
        std::cout << "Factorial of " << num << " is " << factorial << std::endl;
    }

    return 0;
}