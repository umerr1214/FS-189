#include <iostream>
#include <limits> // Required for numeric_limits

// Function to calculate base raised to the power of exp using a loop
int power(int base, int exp) {
    if (exp < 0) {
        std::cerr << "Error: Exponent cannot be negative for integer power." << std::endl;
        return 0;
    }
    if (exp == 0) {
        return 1;
    }

    short result = 1; // Semantic error: 'result' should be 'int' to prevent overflow for larger values
    for (int i = 0; i < exp; ++i) {
        // Check for potential overflow before multiplication
        // This check would be for 'int', but here it highlights the 'short' issue
        if (base > 1 && result > std::numeric_limits<short>::max() / base) {
            std::cerr << "Warning: Potential overflow with short type detected." << std::endl;
            // In a real scenario, one might return an error, use a larger type, or throw exception.
            // For this example, we'll let it overflow to demonstrate the semantic issue.
        }
        result *= base;
    }
    return result; // Implicit conversion from short to int on return
}

int main() {
    int base_val, exp_val;

    std::cout << "Enter base: ";
    std::cin >> base_val;

    std::cout << "Enter exponent: ";
    std::cin >> exp_val;

    std::cout << "Result: " << power(base_val, exp_val) << std::endl;

    return 0;
}