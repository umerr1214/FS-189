#include <iostream> // Required for input/output operations (std::cout, std::endl).

int main() {
    // 1. Declare an integer variable and initialize it.
    // Using a descriptive name 'myInteger' for clarity.
    int myInteger = 10;

    // 2. Declare a pointer and make it point to this integer variable.
    // Using a descriptive name 'integerPtr' for clarity.
    int* integerPtr = &myInteger;

    // 3. Using only the pointer, modify the value of the integer variable.
    // Dereference the pointer (*) to access and modify the value at the memory location it points to.
    *integerPtr = 25; // The value of 'myInteger' is now 25.

    // 4. Print both the new value of the integer variable and its memory address.
    std::cout << "New value of myInteger: " << myInteger << std::endl;
    std::cout << "Memory address of myInteger: " << integerPtr << std::endl;

    return 0; // Indicate successful program execution.
}