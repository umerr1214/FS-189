#include <iostream>

// Function to modify the value pointed to by an integer pointer
// Robustness Issue: Does not handle nullptr, leading to crash on invalid input.
void modifyValue(int* ptr) {
    // This function assumes 'ptr' is a valid, non-null pointer.
    // Dereferencing a nullptr here would cause a segmentation fault or other
    // undefined behavior.
    *ptr *= 2;
}

int main() {
    // Demonstrate valid usage
    int myValue = 10;
    std::cout << "--- Valid Usage ---" << std::endl;
    std::cout << "Original value: " << myValue << std::endl; // Expected: Original value: 10
    modifyValue(&myValue);
    std::cout << "Modified value: " << myValue << std::endl; // Expected: Modified value: 20

    // Demonstrate the robustness issue: Passing a nullptr
    std::cout << "\n--- Demonstrating Robustness Issue (passing nullptr) ---" << std::endl;
    std::cout << "Attempting to call modifyValue with a nullptr..." << std::endl;
    int* nullPtr = nullptr;
    
    // The following line will cause a runtime error (e.g., segmentation fault)
    // because modifyValue attempts to dereference a null pointer without checking.
    modifyValue(nullPtr); 
    
    // This line will likely not be reached if a crash occurs.
    std::cout << "Program continued after calling modifyValue with nullptr (unexpected)." << std::endl;
    
    return 0;
}