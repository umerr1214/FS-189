#include <iostream>

int main() {
    int num;
    long long factorial = 1;

    std::cout << "Enter a non-negative integer: ";
    if (!(std::cin >> num)) {
        // This handles non-numeric input, but doesn't clear the buffer
        // leading to potential issues if not handled by external driver.
        // For robustness issue, we show it fails to recover the stream properly.
        std::cout << "Error: Invalid input. Please enter an integer." << std::endl;
        return 1; // Exit with error
    }

    if (num < 0) {
        std::cout << "Error: Please enter a non-negative integer." << std::endl;
    } else {
        // Factorial for 0 and 1 is 1
        if (num == 0 || num == 1) {
            factorial = 1;
        } else {
            for (int i = 2; i <= num; ++i) {
                // No overflow check for long long.
                // For num > 20, this will produce incorrect results due to overflow.
                factorial *= i;
            }
        }
        std::cout << "Factorial of " << num << " = " << factorial << std::endl;
    }

    return 0;
}