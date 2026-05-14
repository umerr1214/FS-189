#include <iostream>

// Semantic Error: The function takes a const reference but attempts to modify it.
// This is a semantic violation of const-correctness and will result in a compile-time error.
void resetToZero(const int& num) { // Should be 'int& num'
    num = 0; // Compile-time error: assignment of read-only reference 'num'
}

int main() {
    int value = 42;
    std::cout << "Original value: " << value << std::endl;
    // Calling resetToZero will fail to compile due to the const violation in the function body
    resetToZero(value); 
    std::cout << "Value after reset: " << value << std::endl;
    return 0;
}