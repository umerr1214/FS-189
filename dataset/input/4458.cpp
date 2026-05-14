#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    int int_value; // Semantic Error: Reading into an 'int' type
    double value;
    std::cout << "Enter a monetary value: ";
    // If user enters 123.456, only '123' is read into int_value, discarding the decimal part.
    std::cin >> int_value;
    value = static_cast<double>(int_value); // Convert the (truncated) integer to double

    // The formatting itself is correct, but the underlying value is already corrupted.
    std::cout << "$" << std::fixed << std::setprecision(2) << value << std::endl;

    return 0;
}