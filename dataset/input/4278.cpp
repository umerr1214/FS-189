#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    float original_num; // Declared but not initialized/read
    std::cout << "Enter a floating-point number: ";
    // std::cin >> original_num; // SEMANTIC ERROR: Input reading is commented out

    // Explicitly cast to an integer
    // original_num is uninitialized, leading to undefined behavior
    int converted_int = static_cast<int>(original_num);

    // Print original and converted numbers
    std::cout << std::fixed << std::setprecision(1); // For consistent float output
    std::cout << "Original number: " << original_num << std::endl; // Prints garbage
    std::cout << "Integer-converted number: " << converted_int << std::endl; // Prints garbage

    // Calculate and print the difference
    float difference = original_num - converted_int; // Calculation with garbage values
    std::cout << "Difference: " << difference << std::endl;

    return 0;
}