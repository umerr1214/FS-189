#include <iostream>

int main() {
    // Define two integer variables
    int var1 = 10;
    int var2 = 20;

    // Print original values
    std::cout << "Original var1: " << var1 << ", var2: " << var2 << std::endl;

    // Define pointers to these variables
    int* ptr1 = &var1;
    int* ptr2 = nullptr; // Robustness Issue: ptr2 is intentionally a nullptr

    // Modify var1 using ptr1 (this operation is valid)
    *ptr1 += 10;

    // Attempt to modify var2 using ptr2
    // This will cause a runtime error (segmentation fault/crash) due to dereferencing a nullptr.
    *ptr2 += 10; 

    // This line might not be reached if the program crashes earlier
    std::cout << "Modified var1: " << var1 << ", var2: " << var2 << std::endl;
    
    return 0; // Program might not reach here
}