#include <iostream> // For std::cout, std::endl

// Function to calculate the sum of array elements using pointer arithmetic.
// This is the correct, readable, and efficient version.
// It iterates directly using a pointer, avoiding explicit integer indexing for loop control.
int calculateSum(int* arr, int size) {
    long long sum = 0; // Use long long to safely accumulate sum, preventing potential overflow for large sums.

    // A robust solution would ideally check for 'arr == nullptr' if it's a possibility,
    // but the problem implies a valid array for typical use cases.
    // If 'size' is 0 or negative, the loop condition 'ptr < end_ptr' will immediately be false,
    // and 'sum' will correctly remain 0, which is the expected behavior for an empty array.

    // Calculate the end pointer for the loop condition.
    // This pointer points one element past the last element of the array.
    int* end_ptr = arr + size;

    // Iterate using a pointer from the start of the array up to (but not including) the end_ptr.
    // This is a common and idiomatic way to iterate arrays with pointer arithmetic in C++.
    for (int* ptr = arr; ptr < end_ptr; ++ptr) {
        sum += *ptr; // Dereference the current pointer to add the element's value to the sum.
    }

    return static_cast<int>(sum); // Cast back to int as the problem implies an int array sum.
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