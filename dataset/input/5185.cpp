#include <iostream>
#include <iomanip> // Required for std::fixed, std::setprecision
#include <limits>  // Required for std::numeric_limits

int main() {
    float num1;
    float num2; // Declared but not initialized. If input fails, it remains indeterminate.

    std::cout << "Enter first floating-point number: ";
    std::cin >> num1;

    std::cout << "Enter second floating-point number: ";
    // Attempt to read the second number. If input is non-numeric, std::cin will fail,
    // and num2 will retain its indeterminate value. The program does not check for this.
    std::cin >> num2;

    // If std::cin >> num2 failed, num2 holds an indeterminate value.
    // Using an indeterminate value results in Undefined Behavior (UB).
    // This demonstrates a robustness issue as the program does not handle invalid input gracefully.

    float sum = num1 + num2;
    int product_int = static_cast<int>(num1 * num2);

    std::cout << "Sum: " << std::fixed << std::setprecision(6) << sum << std::endl;
    std::cout << "Product (int): " << product_int << std::endl;

    return 0;
}