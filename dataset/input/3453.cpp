#include <iostream>
#include <utility> // For std::swap in a real-world scenario, but implementing it manually here.

// Function to swap the values pointed to by two integer pointers
// This is the correct, robust, and readable version.
void swapNumbers(int* ptr1, int* ptr2) {
    // Robustness check: Ensure pointers are not null before dereferencing.
    if (ptr1 == nullptr || ptr2 == nullptr) {
        std::cerr << "Error: Cannot swap with a null pointer." << std::endl;
        return; // Exit function if pointers are invalid
    }

    // Standard and most readable way to swap values using a temporary variable.
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int val1 = 5;
    int val2 = 10;

    std::cout << "Demonstration in main:" << std::endl;
    std::cout << "Before swap: val1 = " << val1 << ", val2 = " << val2 << std::endl;

    swapNumbers(&val1, &val2);

    std::cout << "After swap: val1 = " << val1 << ", val2 = " << val2 << std::endl;

    int x = -100;
    int y = 500;
    std::cout << "\nBefore swap: x = " << x << ", y = " << y << std::endl;
    swapNumbers(&x, &y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    // Demonstrate null pointer handling (will print an error message)
    int a = 1;
    int* b_ptr = nullptr;
    std::cout << "\nAttempting to swap with a null pointer:" << std::endl;
    std::cout << "Before swap: a = " << a << ", b_ptr = nullptr" << std::endl;
    swapNumbers(&a, b_ptr);
    std::cout << "After swap: a = " << a << ", b_ptr = nullptr (value unchanged for 'a')" << std::endl;


    return 0;
}