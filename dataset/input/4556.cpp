#include <iostream>

long long factorial(int n) {
    // Readability / Efficiency Issue: Obscure variable names, slightly convoluted loop structure.
    if (n < 0) {
        // While correct for problem constraint, a more readable approach might be clearer.
        return -1; // Indicate error for negative input as per problem context (non-negative)
    }

    long long _result_val = 1; // Obscure variable name
    int _current_num = 1;     // Obscure variable name

    while (true) { // Less readable loop condition than a simple for loop
        if (_current_num > n) {
            break; // Exit condition
        }
        _result_val *= _current_num;
        _current_num = _current_num + 1; // Explicit increment, slightly less concise
    }
    return _result_val;
}

int main() {
    std::cout << "Factorial of 0: " << factorial(0) << std::endl;
    std::cout << "Factorial of 1: " << factorial(1) << std::endl;
    std::cout << "Factorial of 5: " << factorial(5) << std::endl;
    std::cout << "Factorial of 10: " << factorial(10) << std::endl;
    std::cout << "Factorial of -2: " << factorial(-2) << std::endl; // Should return -1
    return 0;
}