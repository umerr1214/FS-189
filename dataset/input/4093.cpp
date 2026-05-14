#include <iostream>

// Function definition without nullptr checks
// This version is not robust against null pointers.
void swapValues(int* ptr1, int* ptr2) {
    // Dereferencing a nullptr will lead to undefined behavior and likely a crash.
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

    // Demonstrate robustness issue: passing a nullptr
    // This will likely cause a segmentation fault (crash) when executed.
    int* nullPtr = nullptr;
    int val5 = 100;
    std::cout << "Attempting to swap with a nullptr (this might crash the program):" << std::endl;
    swapValues(&val5, nullPtr); 
    // The following line might not be reached if the program crashes.
    std::cout << "After swap with nullptr (if program survived): val5 = " << val5 << std::endl;

    return 0;
}