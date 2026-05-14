#include <iostream>

void incrementValue(int* ptr) {
    // Robustness issue: No check for nullptr.
    // Dereferencing a nullptr would lead to undefined behavior (e.g., segmentation fault).
    *ptr = *ptr + 1;
}

int main() {
    int x = 10;
    std::cout << "Initial value of x: " << x << std::endl;
    
    // Demonstrate the function's use with a valid pointer
    incrementValue(&x);
    std::cout << "Value of x after increment: " << x << std::endl;

    // This program will run correctly as `main` does not pass a nullptr.
    // However, the `incrementValue` function is not robust against nullptr inputs.
    // If uncommented, `incrementValue(nullptr);` would crash the program.

    return 0;
}