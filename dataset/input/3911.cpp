#include <iostream>

long long calculateFactorial(int n) {
    if (n < 0) {
        return -1; // Indicate error for negative input
    }
    if (n == 0) {
        return 0; // Logical Error: Factorial of 0 is 1, not 0
    }
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
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