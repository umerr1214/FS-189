#include <iostream>
#include <utility> // For std::swap, but we implement our own as per question

// Correct and robust function definition using a temporary variable
void swapValues(int* ptr1, int* ptr2) {
    // Robustness check: Ensure pointers are not null before dereferencing
    if (ptr1 == nullptr || ptr2 == nullptr) {
        // A high-quality solution should handle invalid inputs gracefully.
        // Here, we print an error message and return, indicating no swap occurred.
        std::cerr << "Error: Cannot swap with a null pointer." << std::endl;
        return;
    }
    
    // Standard, readable, and efficient swap using a temporary variable
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    // Demonstrate with valid pointers
    int val1 = 10;
    int val2 = 20;
    std::cout << "Before swap: val1 = " << val1 << ", val2 = " << val2 << std::endl;
    swapValues(&val1, &val2);
    std::cout << "After swap: val1 = " << val1 << ", val2 = " << val2 << std::endl;

    int val3 = -5;
    int val4 = 0;
    std::cout << "Before swap: val3 = " << val3 << ", val4 = " << val4 << std::endl;
    swapValues(&val3, &val4);
    std::cout << "After swap: val3 = " << val3 << ", val4 = " << val4 << std::endl;
    
    // Demonstrate graceful handling of null pointers
    int val5 = 100;
    int* nullPtr = nullptr;
    std::cout << "Attempting to swap val5 with a null pointer:" << std::endl;
    swapValues(&val5, nullPtr);
    // val5 should remain unchanged due to the null pointer check
    std::cout << "After attempted swap with nullptr: val5 = " << val5 << std::endl;

    return 0;
}