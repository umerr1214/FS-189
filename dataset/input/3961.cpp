#include <iostream> // Required for input/output operations

// Function to swap two integer values by reference
// This implementation is correct.
void swapValues(int& a, int& b) {
    int temp = a; // Use a temporary variable to hold one value
    a = b;        // Assign the second value to the first
    b = temp;     // Assign the stored first value to the second
}

int main() {
    int num1, num2; // Declare two integer variables

    // Prompt user for the first integer
    std::cout << "Enter the first integer: ";
    std::cin >> num1; // Read the first integer without input validation

    // Prompt user for the second integer
    std::cout << "Enter the second integer: ";
    std::cin >> num2; // Read the second integer without input validation

    // Display values before swapping
    std::cout << "Before swapping: a = " << num1 << ", b = " << num2 << std::endl;

    // Call the swapValues function to swap the values of num1 and num2
    swapValues(num1, num2);

    // Display values after swapping
    std::cout << "After swapping: a = " << num1 << ", b = " << num2 << std::endl;

    return 0; // Indicate successful execution
}