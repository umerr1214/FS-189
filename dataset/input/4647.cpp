#include <iostream>
#include <limits> // For std::numeric_limits<int>::max() and min()

void swapNumbers(int* a, int* b) {
    // Correct, robust, readable, and efficient implementation.
    // 1. Robustness: Checks for null pointers to prevent dereferencing issues.
    //    If a null pointer is found, it prints a warning and performs no swap,
    //    which is a graceful way to handle invalid inputs for a void function.
    // 2. Readability: Uses the standard and most intuitive temporary variable approach.
    // 3. Efficiency: Optimal for swapping two integers, incurring minimal overhead.
    // 4. Correctness: Works for all integer values, including extreme ones (INT_MAX, INT_MIN),
    //    without causing overflow/underflow issues.
    if (!a || !b) {
        std::cerr << "Warning: Null pointer passed to swapNumbers. No swap performed." << std::endl;
        return;
    }
    
    int temp = *a;
    *a = *b;
    *b = temp;
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

    // Test Case 3: Pointers to same location
    int x3 = 42;
    std::cout << "Test 3: Pointers to same location" << std::endl;
    std::cout << "Before: x3 = " << x3 << std::endl;
    swapNumbers(&x3, &x3); // Should not change value
    std::cout << "After: x3 = " << x3 << std::endl << std::endl;

    // Test Case 4: Values near INT_MAX (no overflow issues)
    int x4 = std::numeric_limits<int>::max();
    int y4 = 1;
    std::cout << "Test 4: Values near INT_MAX" << std::endl;
    std::cout << "Before: x4 = " << x4 << ", y4 = " << y4 << std::endl;
    swapNumbers(&x4, &y4);
    std::cout << "After: x4 = " << x4 << ", y4 = " << y4 << std::endl << std::endl;

    // Test Case 5: Values near INT_MIN (no underflow issues)
    int x5 = std::numeric_limits<int>::min();
    int y5 = -1;
    std::cout << "Test 5: Values near INT_MIN" << std::endl;
    std::cout << "Before: x5 = " << x5 << ", y5 = " << y5 << std::endl;
    swapNumbers(&x5, &y5);
    std::cout << "After: x5 = " << x5 << ", y5 = " << y5 << std::endl << std::endl;

    // Test Case 6: Handling one nullptr (should print warning, no crash, no swap)
    int x6 = 99;
    std::cout << "Test 6: Handling one nullptr" << std::endl;
    std::cout << "Before: x6 = " << x6 << std::endl;
    swapNumbers(&x6, nullptr); // Prints warning, x6 remains 99
    std::cout << "After: x6 = " << x6 << std::endl << std::endl;

    // Test Case 7: Handling the other nullptr (should print warning, no crash, no swap)
    int y7 = 88;
    std::cout << "Test 7: Handling other nullptr" << std::endl;
    std::cout << "Before: y7 = " << y7 << std::endl;
    swapNumbers(nullptr, &y7); // Prints warning, y7 remains 88
    std::cout << "After: y7 = " << y7 << std::endl << std::endl;

    // Test Case 8: Handling both nullptr (should print warning, no crash, no swap)
    std::cout << "Test 8: Handling both nullptr" << std::endl;
    swapNumbers(nullptr, nullptr); // Prints warning
    std::cout << "Swap with both nullptr attempted." << std::endl << std::endl;

    return 0;
}