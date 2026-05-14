#include <iostream>

// Correct function to multiply the value at a memory address by two.
// Includes a nullptr check for robustness and uses a direct, efficient operation.
void multiplyByTwo(int* ptr) {
    // Best practice: Check for nullptr before dereferencing
    if (ptr == nullptr) {
        std::cerr << "Error: Cannot multiplyByTwo a null pointer." << std::endl;
        return; // Exit the function gracefully
    }
    // Direct and efficient operation
    *ptr *= 2;
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

    // Test with nullptr (should handle gracefully)
    int* nullPtr = nullptr;
    // std::cout << "Attempting to call multiplyByTwo with a nullptr..." << std::endl;
    multiplyByTwo(nullPtr); // Should print an error message to cerr and return
    // std::cout << "Program continued gracefully after nullptr call." << std::endl;

    return 0;
}