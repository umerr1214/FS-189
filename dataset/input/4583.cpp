#include <iostream>

// Function to add two numbers pointed to by ptr1 and ptr2,
// and store the result at the location pointed to by sumPtr.
void addNumbers(int* ptr1, int* ptr2, int* sumPtr) {
    // Logical error: performs subtraction instead of addition
    *sumPtr = *ptr1 - *ptr2;
}

int main() {
    int num1 = 5;
    int num2 = 10;
    int sumResult;

    addNumbers(&num1, &num2, &sumResult);
    std::cout << "The sum of " << num1 << " and " << num2 << " is: " << sumResult << std::endl;

    // Test case 2
    num1 = 0;
    num2 = 0;
    addNumbers(&num1, &num2, &sumResult);
    std::cout << "The sum of " << num1 << " and " << num2 << " is: " << sumResult << std::endl;

    // Test case 3
    num1 = -3;
    num2 = 7;
    addNumbers(&num1, &num2, &sumResult);
    std::cout << "The sum of " << num1 << " and " << num2 << " is: " << sumResult << std::endl;

    return 0;
}