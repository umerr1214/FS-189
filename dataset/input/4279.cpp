#include <iostream>

int main() {
    float original_num = 0.0f; // Initialized to 0.0f to make output predictable on invalid input
    std::cout << "Enter a floating-point number: ";
    std::cin >> original_num; // No check for cin.fail()

    // If input fails (e.g., "abc"), original_num remains 0.0f.
    // The program proceeds without notifying the user of the invalid input
    // and computes results based on the default value.
    int converted_int = static_cast<int>(original_num);
    float difference = original_num - converted_int;

    std::cout << "Original number: " << original_num << std::endl;
    std::cout << "Integer converted number: " << converted_int << std::endl;
    std::cout << "Difference: " << difference << std::endl;

    return 0;
}