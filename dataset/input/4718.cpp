#include <iostream> // For std::cout, std::endl

// Function to calculate the sum of array elements using pointer arithmetic.
// Readability Issue: Uses 'goto' statements for loop control, which makes the code
// harder to read, understand, and maintain compared to standard loop constructs (for/while).
// While functionally correct, 'goto' is generally considered bad practice for this purpose.
int calculateSum(int* arr, int size) {
    long long totalSum = 0; // Using long long for sum to prevent potential overflow.
    int currentIndex = 0;   // An integer index is used to track progress, despite using pointer arithmetic for access.

    // Unnecessary early check for empty array using goto.
    // A standard 'for' or 'while' loop would handle size <= 0 gracefully without this.
    if (size <= 0) {
        goto end_function; // Jumps directly to the end, making control flow less linear.
    }

    // Label for the start of the loop.
    loop_start:
        // Access element using pointer arithmetic.
        totalSum += *(arr + currentIndex);
        currentIndex++; // Increment the index for the next element.

        // Loop condition check using goto.
        if (currentIndex < size) {
            goto loop_start; // Jumps back to 'loop_start' if there are more elements.
        }

    // Label for the end of the function.
    end_function:
        return static_cast<int>(totalSum); // Cast back to int.
}

int main() {
    // Test cases
    // Test Case 1: Empty array
    int arr1[] = {};
    std::cout << "Sum of {}: " << calculateSum(arr1, 0) << std::endl; // Expected: 0

    // Test Case 2: Single element
    int arr2[] = {5};
    std::cout << "Sum of {5}: " << calculateSum(arr2, 1) << std::endl; // Expected: 5

    // Test Case 3: Multiple elements
    int arr3[] = {1, 2, 3, 4, 5};
    std::cout << "Sum of {1, 2, 3, 4, 5}: " << calculateSum(arr3, 5) << std::endl; // Expected: 15

    // Test Case 4: Negative numbers
    int arr4[] = {-1, -2, 3};
    std::cout << "Sum of {-1, -2, 3}: " << calculateSum(arr4, 3) << std::endl; // Expected: 0

    // Test Case 5: Mixed numbers
    int arr5[] = {10, -5, 20, -15};
    std::cout << "Sum of {10, -5, 20, -15}: " << calculateSum(arr5, 4) << std::endl; // Expected: 10

    // Test Case 6: Larger array
    int arr6[] = {100, 200, 300, 400, 500};
    std::cout << "Sum of {100, 200, 300, 400, 500}: " << calculateSum(arr6, 5) << std::endl; // Expected: 1500

    return 0;
}