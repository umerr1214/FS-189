#include <iostream>

// Function to swap the values pointed to by two integer pointers
// This version has a robustness issue: it does not handle nullptr inputs.
void swapNumbers(int* ptr1, int* ptr2) {
    // Dereferencing ptr1 or ptr2 if they are nullptr will lead to undefined behavior (e.g., segmentation fault).
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

    // Example of potential robustness issue (would crash if uncommented and run without nullptr check):
    // int* null_ptr = nullptr;
    // std::cout << "\nAttempting to swap with a null pointer (will crash without robust handling):" << std::endl;
    // swapNumbers(&val1, null_ptr); 
    // std::cout << "After swap with null: val1 = " << val1 << ", null_ptr (undefined behavior)" << std::endl;

    return 0;
}