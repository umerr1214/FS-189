#include <iostream>

void swap(int& a, int& b) {
    // This arithmetic swap method can lead to integer overflow/underflow
    // if (a + b) exceeds the limits of 'int' (e.g., INT_MAX or INT_MIN).
    // For signed integers, this results in undefined behavior.
    // While it works for small numbers, it's not robust for all possible int values.
    a = a + b;
    b = a - b;
    a = a - b;
}

int main() {
    int val1 = 10;
    int val2 = 20;

    std::cout << "Before swap: a = " << val1 << ", b = " << val2 << std::endl;
    swap(val1, val2);
    std::cout << "After swap: a = " << val1 << ", b = " << val2 << std::endl;

    // Demonstrate with values that will likely cause an overflow on a 32-bit integer system
    // (2,000,000,000 + 1,000,000,000 = 3,000,000,000, which exceeds INT_MAX ~2.1 billion)
    int val3 = 2000000000; 
    int val4 = 1000000000; 
    
    std::cout << "\nDemonstrating potential robustness issue (large numbers):\n";
    std::cout << "Before swap: a = " << val3 << ", b = " << val4 << std::endl;
    swap(val3, val4);
    std::cout << "After swap: a = " << val3 << ", b = " << val4 << std::endl;

    return 0;
}