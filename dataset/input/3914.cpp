#include <iostream>

// Function to calculate factorial with readability/efficiency issue (recursive, less efficient than iterative)
long long calculateFactorial(int num) {
    if (num < 0) {
        // Appropriately handle negative input
        return -1; // Indicates an error or undefined factorial
    }
    if (num == 0) {
        return 1;
    }
    // Recursive approach, which can be less efficient due to function call overhead
    // and potentially lead to stack overflow for very large inputs (though not an issue for typical factorial range fitting long long)
    return (long long)num * calculateFactorial(num - 1);
}

int main() {
    int inputNumber;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> inputNumber;

    long long resultFactorial = calculateFactorial(inputNumber);

    if (resultFactorial == -1) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
    } else {
        std::cout << "The factorial of " << inputNumber << " is: " << resultFactorial << std::endl;
    }

    return 0;
}