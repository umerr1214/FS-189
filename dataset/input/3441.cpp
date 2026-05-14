#include <iostream>

/**
 * @brief Calculates base raised to the power of exp.
 *        Assumes exp is a non-negative integer (exp >= 0) based on the problem context
 *        and the `int` return type.
 *        For exp = 0, returns 1 (base^0 = 1).
 *        Does not explicitly handle negative exponents (assumes valid non-negative input).
 *        Does not explicitly check for integer overflow, which may occur for very large inputs
 *        that exceed the capacity of an `int`.
 * @param base The base integer.
 * @param exp The exponent integer (expected to be non-negative).
 * @return The result of base^exp as an integer.
 */
int power(int base, int exp) {
    int result = 1; // Initialize result to 1. This correctly handles base^0 = 1.

    // Loop 'exp' times to multiply base by itself.
    // If exp is 0, the loop does not run, and 'result' (1) is returned, which is correct.
    // If exp is negative, the loop also does not run, and 'result' (1) is returned.
    // For this 'correct version', we assume valid non-negative 'exp' as per problem context.
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }

    return result;
}

int main() {
    int base, exp;

    std::cout << "Enter base: ";
    std::cin >> base;

    std::cout << "Enter exponent: ";
    std::cin >> exp;

    int result = power(base, exp);
    std::cout << "Result: " << result << std::endl;

    return 0;
}