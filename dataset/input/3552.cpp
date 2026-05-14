#include <iostream>

// Function to increment the value a pointer points to by 5 and return the new value
int incrementPointerValue(int* ptr) {
    *ptr += 5;
    return *ptr;
}

int main() {
    int myValue = 10;
    std::cout << "Original value: " << myValue << std::endl;

    // Semantic Error: Passing an int by value where a pointer (int*) is expected.
    // This will cause a compilation error due to type mismatch.
    int newValue = incrementPointerValue(myValue); 
    std::cout << "New value after increment: " << newValue << std::endl;
    std::cout << "Value in main after function call: " << myValue << std::endl;

    int anotherValue = -3;
    std::cout << "Original value: " << anotherValue << std::endl;
    // The following line would be the correct usage:
    // int newAnotherValue = incrementPointerValue(&anotherValue);
    // std::cout << "New value after increment: " << newAnotherValue << std::endl;
    // std::cout << "Value in main after function call: " << anotherValue << std::endl;

    return 0;
}