#include <iostream>

int main() {
    // Define two integer variables
    int num1 = 10;
    int num2 = 20;

    // Print original values
    std::cout << "Original var1: " << num1 << ", var2: " << num2 << std::endl;

    // Define pointers to these variables
    int* pNum1 = &num1;
    int* pNum2 = &num2;

    // Modify the values of the variables using pointers by incrementing each by 10
    *pNum1 += 10; // Directly increment num1's value via its pointer
    *pNum2 += 10; // Directly increment num2's value via its pointer

    // Print modified values
    std::cout << "Modified var1: " << num1 << ", var2: " << num2 << std::endl;

    return 0;
}