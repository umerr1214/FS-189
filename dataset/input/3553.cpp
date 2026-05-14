#include <iostream>

// Function to increment the value pointed to by ptr by 5 and return the new value.
// Lacks robustness: does not handle nullptr input for ptr.
int incrementPointerValue(int* ptr) {
    // This line will cause a crash (segmentation fault) if ptr is nullptr.
    *ptr += 5;
    return *ptr;
}

int main() {
    int value = 10;
    int* p = &value;

    std::cout << "Original value: " << value << std::endl; // Expected: 10

    // Valid usage
    int newValue = incrementPointerValue(p);
    std::cout << "Value after increment (valid ptr): " << value << std::endl; // Expected: 15
    std::cout << "Returned new value (valid ptr): " << newValue << std::endl; // Expected: 15

    std::cout << "\nAttempting to call with a nullptr (EXPECTED CRASH)..." << std::endl;
    int* nullPtr = nullptr;
    // This call will likely crash the program due to dereferencing nullptr inside the function.
    int resultFromNull = incrementPointerValue(nullPtr);
    std::cout << "This line may not be reached if a crash occurs. Result: " << resultFromNull << std::endl;

    return 0; // This line may not be reached.
}