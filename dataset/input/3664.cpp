#include <iostream>

// Syntax error: Missing return type for the function
incrementValue(int* ptr) {
    (*ptr)++; // Attempt to increment the value pointed to
}

int main() {
    int value = 10;
    std::cout << "Original value: " << value << std::endl;
    incrementValue(&value); // Function call
    std::cout << "Incremented value: " << value << std::endl;
    return 0;
}