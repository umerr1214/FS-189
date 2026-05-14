#include <iostream> // For std::cout and std::endl
#include <cstdio>   // For printf

int main() {
    // Declare an integer variable and initialize it.
    int myInt = 10;

    // Declare a pointer and make it point to this integer variable.
    int* ptr = &myInt;

    // Using only the pointer, modify the value of the integer variable.
    *ptr = 20;

    // Print the new value of the integer variable.
    std::cout << "New value of myInt: " << myInt << std::endl;

    // Robustness Issue: Using an incorrect format specifier (%d) for printing a pointer
    // with printf. This leads to Undefined Behavior.
    // A robust solution would cast ptr to void* and use %p, or simply use std::cout << ptr.
    printf("Memory address of myInt (potentially incorrect/UB): %d\n", ptr);

    return 0;
}