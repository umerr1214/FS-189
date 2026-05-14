#include <iostream>  // Required for input/output operations (std::cin, std::cout)
#include <iomanip>   // Required for output formatting (std::fixed, std::setprecision)

int main() {
    // Declare variables to store the two floating-point numbers
    float firstNumber;
    float secondNumber;

    // Prompt the user to enter the first number and read it
    std::cout << "Please enter the first floating-point number: ";
    std::cin >> firstNumber;

    // Prompt the user to enter the second number and read it
    std::cout << "Please enter the second floating-point number: ";
    std::cin >> secondNumber;

    // Calculate their sum and store it as a float
    float sum = firstNumber + secondNumber;

    // Calculate their product and explicitly cast it to an int before storing
    // Note: Casting from float to int truncates the decimal part.
    int integerProduct = static_cast<int>(firstNumber * secondNumber);

    // Print both the float sum and the integer product
    // Use std::fixed and std::setprecision(6) for consistent float output
    // Use '\n' for newlines, which is generally more efficient than std::endl
    std::cout << "Sum: " << std::fixed << std::setprecision(6) << sum << '\n';
    std::cout << "Product (int): " << integerProduct << '\n';

    return 0; // Indicate successful program execution
}