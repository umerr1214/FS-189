#include <iostream>

// Function to modify the value pointed to by an integer pointer
// Readability / Efficiency Issue: Uses a less idiomatic and potentially less efficient way to double the value.
void modifyValue(int* ptr) {
    // While functionally correct, '*ptr = *ptr + *ptr;' is less idiomatic
    // and potentially less efficient than '*ptr *= 2;' or '*ptr = *ptr * 2;'
    // for doubling an integer value. It slightly reduces readability for a common operation.
    *ptr = *ptr + *ptr;
}

int main() {
    int myValue = 7;
    std::cout << "Original value: " << myValue << std::endl;
    modifyValue(&myValue);
    std::cout << "Modified value: " << myValue << std::endl;

    int anotherValue = -5;
    std::cout << "Original value: " << anotherValue << std::endl;
    modifyValue(&anotherValue);
    std::cout << "Modified value: " << anotherValue << std::endl;

    return 0;
}