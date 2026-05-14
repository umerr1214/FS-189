#include <iostream> // Required for input/output operations like std::cout

// Function: addNumbers
// Description: Calculates the sum of two integers pointed to by ptr1 and ptr2,
//              and stores the result at the memory location pointed to by sumPtr.
// Parameters:
//   ptr1: Pointer to the first integer.
//   ptr2: Pointer to the second integer.
//   sumPtr: Pointer to the integer where the sum will be stored.
// Precondition: ptr1, ptr2, and sumPtr must point to valid integer locations (not nullptr).
void addNumbers(int* ptr1, int* ptr2, int* sumPtr) {
    // Dereference ptr1 and ptr2 to get their values, sum them,
    // and then dereference sumPtr to store the calculated result.
    *sumPtr = *ptr1 + *ptr2;
}

int main() {
    // Declare three integer variables with descriptive names.
    // num1 and num2 will hold the numbers to be added.
    // result will store the sum.
    int num1 = 15;
    int num2 = 25;
    int result = 0; // Initialize result to 0 for good practice

    // Call addNumbers, passing the addresses of num1, num2, and result.
    // The function will calculate num1 + num2 and store it in result.
    addNumbers(&num1, &num2, &result);

    // Print the original numbers and their sum to clearly demonstrate functionality.
    std::cout << "The sum of " << num1 << " and " << num2 << " is: " << result << std::endl; // Expected output: 40

    // Demonstrate with another set of numbers, including negative values.
    int valA = -10;
    int valB = 5;
    int sumResult = 0; // Initialize sumResult
    addNumbers(&valA, &valB, &sumResult);
    std::cout << "The sum of " << valA << " and " << valB << " is: " << sumResult << std::endl; // Expected output: -5

    // Demonstrate with zero as one of the operands.
    int zero = 0;
    int positive = 100;
    int zeroSum = 0; // Initialize zeroSum
    addNumbers(&zero, &positive, &zeroSum);
    std::cout << "The sum of " << zero << " and " << positive << " is: " << zeroSum << std::endl; // Expected output: 100

    return 0; // Indicate successful program execution
}