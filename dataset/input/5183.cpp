#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    float num1, num2;

    // Prompt for the first number
    std::cout << "Enter the first floating-point number: ";
    std::cin >> num1;

    // Prompt for the second number
    std::cout << "Enter the second floating-point number: ";
    std::cin >> num2;

    // Calculate sum incorrectly (logical error: subtraction instead of addition)
    float sum = num1 - num2; // Should be num1 + num2

    // Calculate product incorrectly (logical error: sum of numbers cast to int instead of product)
    int product_int = static_cast<int>(num1 + num2); // Should be static_cast<int>(num1 * num2)

    // Print the float sum
    std::cout << std::fixed << std::setprecision(2); // Format output for floats
    std::cout << "Sum (float): " << sum << std::endl;

    // Print the integer product
    std::cout << "Product (int): " << product_int << std::endl;

    return 0;
}