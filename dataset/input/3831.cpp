#include <iostream>

// Function to modify the value pointed to by an integer pointer
// Correct Version: Handles nullptr gracefully and uses an idiomatic operation.
void modifyValue(int* ptr) {
    // Check if the pointer is not null before dereferencing to prevent crashes.
    if (ptr) {
        *ptr *= 2; // Idiomatic and efficient way to double the value.
    }
    // If ptr is nullptr, the function does nothing, which is safe behavior.
}

int main() {
    // Demonstrate usage with a valid integer
    int myValue = 15;
    std::cout << "Original value: " << myValue << std::endl;
    modifyValue(&myValue);
    std::cout << "Modified value: " << myValue << std::endl; // Expected: 30

    // Demonstrate usage with zero
    int zeroValue = 0;
    std::cout << "Original value: " << zeroValue << std::endl;
    modifyValue(&zeroValue);
    std::cout << "Modified value: " << zeroValue << std::endl; // Expected: 0

    // Demonstrate usage with a negative value
    int negativeValue = -8;
    std::cout << "Original value: " << negativeValue << std::endl;
    modifyValue(&negativeValue);
    std::cout << "Modified value: " << negativeValue << std::endl; // Expected: -16

    // Demonstrate robust handling of nullptr
    std::cout << "\nDemonstrating nullptr handling:" << std::endl;
    int* nullPtr = nullptr;
    std::cout << "Calling modifyValue with nullptr (should do nothing and not crash)." << std::endl;
    modifyValue(nullPtr);
    std::cout << "Program continued successfully after calling modifyValue with nullptr." << std::endl;

    return 0;
}