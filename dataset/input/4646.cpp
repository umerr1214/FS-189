#include <iostream>
#include <limits> // For std::numeric_limits<int>::max() and min()

void swapNumbers(int* a, int* b) {
    // Readability/Efficiency Issue:
    // 1. Less readable than the standard temporary variable approach for many developers.
    // 2. Can lead to integer overflow or underflow if the sum (*a + *b) exceeds
    //    std::numeric_limits<int>::max() or goes below std::numeric_limits<int>::min().
    //    This results in incorrect swap behavior for those specific extreme values.
    //
    // Added a basic nullptr check to prevent crashes, as the main issue here is not robustness
    // regarding null pointers, but rather the arithmetic swap's inherent problems.
    if (!a || !b) {
        std::cerr << "Warning: Null pointer passed to swapNumbers. No swap performed." << std::endl;
        return;
    }

    *a = *a + *b; // Potential overflow/underflow here
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    // Test Case 1: Normal swap
    int x1 = 5, y1 = 10;
    std::cout << "Test 1: Normal swap" << std::endl;
    std::cout << "Before: x1 = " << x1 << ", y1 = " << y1 << std::endl;
    swapNumbers(&x1, &y1);
    std::cout << "After: x1 = " << x1 << ", y1 = " << y1 << std::endl << std::endl;

    // Test Case 2: Negative numbers
    int x2 = -3, y2 = -7;
    std::cout << "Test 2: Negative numbers" << std::endl;
    std::cout << "Before: x2 = " << x2 << ", y2 = " << y2 << std::endl;
    swapNumbers(&x2, &y2);
    std::cout << "After: x2 = " << x2 << ", y2 = " << y2 << std::endl << std::endl;

    // Test Case 3: Pointers to same location (this arithmetic swap works correctly here)
    int x3 = 42;
    std::cout << "Test 3: Pointers to same location" << std::endl;
    std::cout << "Before: x3 = " << x3 << std::endl;
    swapNumbers(&x3, &x3); // Value should remain 42
    std::cout << "After: x3 = " << x3 << std::endl << std::endl;

    // Test Case 4: Demonstrating potential overflow leading to incorrect swap
    // If x4 = INT_MAX and y4 = 1, then x4 + y4 overflows, resulting in INT_MIN.
    // This leads to incorrect final values for x4 and y4.
    int x4 = std::numeric_limits<int>::max(); // Maximum int value
    int y4 = 1;
    std::cout << "Test 4: Demonstrating overflow issue (x = INT_MAX, y = 1)" << std::endl;
    std::cout << "Before: x4 = " << x4 << ", y4 = " << y4 << std::endl;
    swapNumbers(&x4, &y4);
    std::cout << "After: x4 = " << x4 << ", y4 = " << y4 << std::endl << std::endl;
    // Expected correct swap: x4 = 1, y4 = INT_MAX
    // Actual result due to overflow: x4 = 1, y4 = INT_MIN

    // Test Case 5: Demonstrating potential underflow leading to incorrect swap
    // If x5 = INT_MIN and y5 = -1, then x5 + y5 underflows, resulting in INT_MAX.
    // This leads to incorrect final values for x5 and y5.
    int x5 = std::numeric_limits<int>::min(); // Minimum int value
    int y5 = -1;
    std::cout << "Test 5: Demonstrating underflow issue (x = INT_MIN, y = -1)" << std::endl;
    std::cout << "Before: x5 = " << x5 << ", y5 = " << y5 << std::endl;
    swapNumbers(&x5, &y5);
    std::cout << "After: x5 = " << x5 << ", y5 = " << y5 << std::endl << std::endl;
    // Expected correct swap: x5 = -1, y5 = INT_MIN
    // Actual result due to underflow: x5 = -1, y5 = INT_MAX

    // Test Case 6: Handling nullptr (should print warning and do nothing)
    int x6 = 99;
    std::cout << "Test 6: Handling one nullptr" << std::endl;
    std::cout << "Before: x6 = " << x6 << std::endl;
    swapNumbers(&x6, nullptr); // Prints warning, x6 remains 99
    std::cout << "After: x6 = " << x6 << std::endl << std::endl;

    return 0;
}