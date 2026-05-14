#include <iostream> // For std::cin, std::cout, std::endl

// Renamed main for testing purposes
int solution_main() {
    int number; // Descriptive variable name
    // C++ idiomatic input
    std::cout << "Enter a number: ";
    std::cin >> number;

    // Standard for loop for clear and concise iteration
    for (int multiplier = 1; multiplier <= 10; ++multiplier) {
        // Using `long long` for the product to prevent potential integer overflow,
        // enhancing robustness and quality, even for very large `number` values.
        long long product = static_cast<long long>(number) * multiplier;
        // C++ idiomatic output with clear formatting
        std::cout << number << " * " << multiplier << " = " << product << std::endl;
    }
    return 0;
}

// The actual main function that calls the solution logic
int main() {
    return solution_main();
}