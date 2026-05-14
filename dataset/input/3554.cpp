#include <iostream>

// Function to increment the value pointed to by ptr by 5 and return the new value.
// Contains a minor readability/efficiency issue by using an unnecessary temporary variable
// and not directly returning the modified dereferenced pointer.
int incrementPointerValue(int* ptr) {
    // Stores the original value, which is then used to calculate the new value.
    // This is slightly less efficient/readable than simply `*ptr += 5; return *ptr;`
    int oldValue = *ptr;
    *ptr = oldValue + 5;
    return oldValue + 5; // Returns the calculated new value, but *ptr already holds it.
}

int main() {
    int myValue = 20;
    std::cout << "Original value: " << myValue << std::endl; // Expected: 20

    int newValue = incrementPointerValue(&myValue);
    std::cout << "Value after increment: " << myValue << std::endl; // Expected: 25
    std::cout << "Returned new value: " << newValue << std::endl;   // Expected: 25

    int anotherValue = -3;
    std::cout << "\nOriginal value: " << anotherValue << std::endl; // Expected: -3
    newValue = incrementPointerValue(&anotherValue);
    std::cout << "Value after increment: " << anotherValue << std::endl; // Expected: 2
    std::cout << "Returned new value: " << newValue << std::endl;   // Expected: 2

    return 0;
}