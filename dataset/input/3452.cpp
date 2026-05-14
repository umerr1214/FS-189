#include <iostream>

// Function to swap the values pointed to by two integer pointers
// This version uses an arithmetic swap method, which has readability and efficiency issues.
void swapNumbers(int* ptr1, int* ptr2) {
    // This method avoids a temporary variable but is less readable
    // and can lead to integer overflow if the sum of *ptr1 and *ptr2 exceeds INT_MAX or INT_MIN.
    *ptr1 = *ptr1 + *ptr2; // If *ptr1 = 2*10^9, *ptr2 = 2*10^9, sum overflows int
    *ptr2 = *ptr1 - *ptr2;
    *ptr1 = *ptr1 - *ptr2;
}

int main() {
    int val1 = 5;
    int val2 = 10;

    std::cout << "Demonstration in main:" << std::endl;
    std::cout << "Before swap: val1 = " << val1 << ", val2 = " << val2 << std::endl;

    swapNumbers(&val1, &val2);

    std::cout << "After swap: val1 = " << val1 << ", val2 = " << val2 << std::endl;

    int large_val1 = 2000000000; // 2 * 10^9
    int large_val2 = 1000000000; // 1 * 10^9
    std::cout << "\nDemonstrating with large values (potential overflow risk):" << std::endl;
    std::cout << "Before swap: large_val1 = " << large_val1 << ", large_val2 = " << large_val2 << std::endl;
    swapNumbers(&large_val1, &large_val2);
    std::cout << "After swap: large_val1 = " << large_val1 << ", large_val2 = " << large_val2 << std::endl;


    return 0;
}