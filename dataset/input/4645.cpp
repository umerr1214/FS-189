#include <iostream>
#include <limits> // For INT_MAX, INT_MIN (though not directly used in problematic swap)

void swapNumbers(int* a, int* b) {
    // Robustness issue: This implementation does not handle null pointer inputs.
    // Dereferencing a nullptr will lead to a segmentation fault (program crash).
    // For example, if 'a' or 'b' is nullptr, '*a' or '*b' will cause a crash.
    int temp = *a; // Potential crash if 'a' is nullptr
    *a = *b;       // Potential crash if 'a' or 'b' is nullptr
    *b = temp;     // Potential crash if 'b' is nullptr
}

int main() {
    // Test Case 1: Positive integers
    int x1 = 5, y1 = 10;
    std::cout << "Test 1: Normal swap" << std::endl;
    std::cout << "Before: x1 = " << x1 << ", y1 = " << y1 << std::endl;
    swapNumbers(&x1, &y1);
    std::cout << "After: x1 = " << x1 << ", y1 = " << y1 << std::endl << std::endl;

    // Test Case 2: Negative integers
    int x2 = -3, y2 = -7;
    std::cout << "Test 2: Negative numbers" << std::endl;
    std::cout << "Before: x2 = " << x2 << ", y2 = " << y2 << std::endl;
    swapNumbers(&x2, &y2);
    std::cout << "After: x2 = " << x2 << ", y2 = " << y2 << std::endl << std::endl;

    // Test Case 3: Pointers to same location (temporary variable swap handles this correctly)
    int x3 = 42;
    std::cout << "Test 3: Pointers to same location" << std::endl;
    std::cout << "Before: x3 = " << x3 << std::endl;
    swapNumbers(&x3, &x3); // Value should remain 42
    std::cout << "After: x3 = " << x3 << std::endl << std::endl;

    // Test Case 4: Robustness issue demonstration - passing one nullptr.
    // This call is expected to cause a segmentation fault (program crash).
    std::cout << "Test 4: Attempting swap with one nullptr (expected crash/segmentation fault)..." << std::endl;
    int x4 = 100;
    // The program is expected to crash immediately after this call.
    swapNumbers(&x4, nullptr);
    std::cout << "This line should not be reached." << std::endl; // This line will likely not be printed.
    
    return 0; // Program will likely terminate before reaching here.
}