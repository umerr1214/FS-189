#include <iostream>

long long calculateFactorial(int n) {
    if (n < 0) {
        return -1; // Indicate error for negative input
    }
    if (n == 0) {
        return 1;
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
    std::cin >> num // Syntax Error: Missing semicolon here

    long long fact = calculateFactorial(num);

    if (fact == -1) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
    } else {
        std::cout << "The factorial of " << num << " is: " << fact << endl; // Syntax Error: Missing std:: before endl
    }

    return 0;
}