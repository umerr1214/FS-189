#include <iostream>

// Function to multiply the value at a memory address by two
// Introduces an unnecessary temporary variable, impacting readability and minor efficiency.
void multiplyByTwo(int* ptr) {
    // Readability/Efficiency issue: Using an unnecessary temporary variable
    int current_value_at_address = *ptr; // Unnecessary temporary variable
    *ptr = current_value_at_address + current_value_at_address; // Less direct than *= 2 or * 2
}

int main() {
    int num1 = 5;
    // std::cout << "Initial value of num1: " << num1 << std::endl;
    multiplyByTwo(&num1);
    std::cout << num1 << std::endl; // Expected: 10

    int num2 = 0;
    // std::cout << "Initial value of num2: " << num2 << std::endl;
    multiplyByTwo(&num2);
    std::cout << num2 << std::endl; // Expected: 0

    int num3 = -3;
    // std::cout << "Initial value of num3: " << num3 << std::endl;
    multiplyByTwo(&num3);
    std::cout << num3 << std::endl; // Expected: -6

    return 0;
}