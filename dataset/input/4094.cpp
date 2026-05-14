#include <iostream>

// Function definition using arithmetic swap (less readable, potential for overflow)
void swapValues(int* ptr1, int* ptr2) {
    // This method uses arithmetic operations to swap values.
    // It is generally considered less readable than using a temporary variable
    // and can lead to integer overflow if the sum of the two integers exceeds
    // the maximum value for an int, resulting in incorrect behavior for extreme values.
    // For this specific example, we assume valid non-null pointers are passed.
    
    *ptr1 = *ptr1 + *ptr2; // ptr1 now holds sum of original *ptr1 and *ptr2
    *ptr2 = *ptr1 - *ptr2; // ptr2 now holds original *ptr1 value
    *ptr1 = *ptr1 - *ptr2; // ptr1 now holds original *ptr2 value
}

int main() {
    // Demonstrate with typical integer values
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
    
    // Demonstrate with other values
    int val5 = 100;
    int val6 = 200;
    std::cout << "Before swap: val5 = " << val5 << ", val6 = " << val6 << std::endl;
    swapValues(&val5, &val6);
    std::cout << "After swap: val5 = " << val5 << ", val6 = " << val6 << std::endl;

    return 0;
}