#include <iostream>

// Correct implementation of swapValues, but the main function will call it semantically incorrectly.
void swapValues(int* ptr1, int* ptr2) {
    // A robust function would check for nullptr here.
    // Without checks, dereferencing a nullptr will lead to undefined behavior (semantic error).
    int temp = *ptr1;
    *ptr1 = *ptr2; // If ptr2 is nullptr, dereferencing it here is a semantic error
    *ptr2 = temp;  // If ptr2 is nullptr, dereferencing it here is a semantic error
}

int main() {
    int a = 10;
    int* b_ptr = nullptr; // One pointer is intentionally a null pointer

    std::cout << "Before swap: a = " << a << ", b_ptr (address) = " << b_ptr << std::endl;

    // Calling swapValues with a nullptr leads to a semantic error (undefined behavior/crash)
    // because the function will attempt to dereference b_ptr.
    swapValues(&a, b_ptr);

    // This part of the code will likely not be reached if a crash occurs.
    std::cout << "After swap: a = " << a << ", b_ptr (address) = " << b_ptr << std::endl;
    return 0;
}