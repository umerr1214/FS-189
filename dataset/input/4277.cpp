#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    float original_num;
    std::cout << "Enter a floating-point number: ";
    std::cin >> original_num;

    // Explicitly cast to an integer
    int converted_int = static_cast<int>(original_num);

    // Print original and converted numbers
    std::cout << std::fixed << std::setprecision(1); // For consistent float output
    std::cout << "Original number: " << original_num << std::endl;
    std::cout << "Integer-converted number: " << converted_int << std::endl;

    // Calculate and print the difference - LOGICAL ERROR HERE
    // Instead of original_num - converted_int, it calculates original_num - original_num
    float difference = original_num - original_num; // This will always be 0.0
    std::cout << "Difference: " << difference << std::endl;

    return 0;
}