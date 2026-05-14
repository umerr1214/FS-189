#include <iostream>

// Function to add two numbers pointed to by ptr1 and ptr2,
// and store the result at the location pointed to by sumPtr.
void addNumbers(int* ptr1, int* ptr2, int* sumPtr) {
    // Semantic error: If sumPtr is uninitialized or null, dereferencing it here leads to undefined behavior.
    *sumPtr = *ptr1 + *ptr2;
}

int main() {
    int num1 = 5;
    int num2 = 10;
    int* sumPtr; // Semantic error: sumPtr is declared but not initialized to point to valid memory.

    // Calling addNumbers with an uninitialized pointer for sumPtr.
    // This will lead to writing to an arbitrary memory location, causing undefined behavior or a crash.
    addNumbers(&num1, &num2, sumPtr);

    // If the program hasn't crashed, trying to print the value from an invalid memory location.
    std::cout << "The sum of " << num1 << " and " << num2 << " is: " << *sumPtr << std::endl;

    // To prevent further undefined behavior or crashes in subsequent test cases,
    // we would typically initialize sumPtr properly here.
    // For demonstration of the error, we keep it uninitialized for the first call.
    // Let's use a valid pointer for the next calls to show how it should work.
    int validSumResult;
    sumPtr = &validSumResult;

    // Test case 2 (now with a valid pointer)
    num1 = 0;
    num2 = 0;
    addNumbers(&num1, &num2, sumPtr);
    std::cout << "The sum of " << num1 << " and " << num2 << " is: " << *sumPtr << std::endl;

    // Test case 3 (now with a valid pointer)
    num1 = -3;
    num2 = 7;
    addNumbers(&num1, &num2, sumPtr);
    std::cout << "The sum of " << num1 << " and " << num2 << " is: " << *sumPtr << std::endl;

    return 0;
}