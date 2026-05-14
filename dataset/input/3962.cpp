#include <iostream> // Required for input/output operations

// Function to swap two integer values by reference using XOR bitwise operations
// This avoids a temporary variable but is generally less readable than the standard approach.
void swapValues(int& a, int& b) {
    // XOR swap algorithm:
    // 1. a becomes a^b
    // 2. b becomes (a^b)^b which simplifies to a
    // 3. a becomes (a^b)^a which simplifies to b
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main() {
    int num1, num2; // Declare two integer variables

    // Prompt user for the first integer
    std::cout << "Enter the first integer: ";
    std::cin >> num1; // Read the first integer

    // Prompt user for the second integer
    std::cout << "Enter the second integer: ";
    std::cin >> num2; // Read the second integer

    // Display values before swapping
    std::cout << "Before swapping: a = " << num1 << ", b = " << num2 << std::endl;

    // Call the swapValues function to swap the values of num1 and num2
    swapValues(num1, num2);

    // Display values after swapping
    std::cout << "After swapping: a = " << num1 << ", b = " << num2 << std::endl;

    return 0; // Indicate successful execution
}