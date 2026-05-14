#include <iostream>

long long calculateFactorial(int n) { // Function signature returns long long
    if (n < 0) {
        return -1; // Indicate error for negative input
    }
    if (n == 0) {
        return 1;
    }
    int result = 1; // Semantic Error: 'result' should be long long to prevent overflow for large factorials
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result; // Implicit conversion from int to long long, but value might already be corrupted by overflow
}

int main() {
    int num;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> num;

    long long fact = calculateFactorial(num);

    if (fact == -1) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
    } else {
        std::cout << "The factorial of " << num << " is: " << fact << std::endl;
    }

    return 0;
}