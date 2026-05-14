#include <iostream>

// Function to increment the value a pointer points to by 5 and return the new value
int incrementPointerValue(int* ptr) {
    int originalValue = *ptr; // Store original value
    *ptr += 5;                 // Increment the value
    return originalValue;      // Logical Error: Returns the original value instead of the new, incremented value
}

int main() {
    int myValue = 10;
    std::cout << "Original value: " << myValue << std::endl;

    int newValue = incrementPointerValue(&myValue);
    std::cout << "Function returned: " << newValue << std::endl;
    std::cout << "Value in main after function call: " << myValue << std::endl;

    int anotherValue = -3;
    std::cout << "Original value: " << anotherValue << std::endl;
    int newAnotherValue = incrementPointerValue(&anotherValue);
    std::cout << "Function returned: " << newAnotherValue << std::endl;
    std::cout << "Value in main after function call: " << anotherValue << std::endl;

    return 0;
}