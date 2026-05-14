#include <iostream> // For std::cout, std::endl

// Function to calculate the sum of array elements using pointer arithmetic.
// Robustness Issue: This function does not handle a 'nullptr' for the 'arr' argument.
// If 'arr' is 'nullptr' and 'size' is greater than 0, dereferencing '*ptr' inside the loop
// will lead to a segmentation fault (crash). A robust solution would include a check
// like 'if (arr == nullptr && size > 0) { /* handle error */ }'.
int calculateSum(int* arr, int size) {
    long long sum = 0; // Using long long for sum to prevent potential overflow for large sums.

    // No check for 'arr == nullptr' is performed.
    // If 'arr' is 'nullptr' and 'size > 0', the loop will attempt to dereference 'nullptr'.
    for (int* ptr = arr; ptr < arr + size; ++ptr) {
        sum += *ptr; // Dereferencing 'nullptr' if 'arr' is null and 'size' is positive.
    }

    return static_cast<int>(sum); // Cast back to int as the problem implies an int array sum.
}

int main() {
    // Standard test cases where 'arr' is a valid pointer.
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

    // IMPORTANT: To demonstrate the robustness issue (crashing with nullptr),
    // a specific test case in the JSON driver will pass 'nullptr' as 'arr' with 'size > 0'.
    // We avoid calling it directly in main to allow the program to complete other tests gracefully.
    // Example of a call that would crash:
    // int* null_ptr = nullptr;
    // std::cout << "Sum of nullptr with size 3: " << calculateSum(null_ptr, 3) << std::endl;

    return 0;
}