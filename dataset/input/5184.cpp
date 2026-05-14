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

    // Calculate sum and store as int (semantic error: implicit conversion, loss of precision,
    // violates requirement to store as float)
    int sum_val = num1 + num2; // The question explicitly asks to store the sum as a 'float'.
                               // This performs an implicit conversion from float to int,
                               // losing any fractional part.

    // Calculate product, explicitly cast to int, and store (correct)
    int product_int = static_cast<int>(num1 * num2);

    // Print the sum (which is now an int, not a float as requested)
    // The output formatting for float is still applied, but on an int variable,
    // which might lead to unexpected visual output or just print the integer.
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Sum (float): " << sum_val << std::endl; // Prints an int, not a float.

    // Print the integer product
    std::cout << "Product (int): " << product_int << std::endl;

    return 0;
}