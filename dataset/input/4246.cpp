#include <iostream>

int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i // Missing semicolon here, will cause a syntax error
        }
    }
    return -1;
}

void run_test(int arr[], int size, int target, int expected, int test_num) {
    // This driver code assumes the linear_search function will compile and run.
    // For a syntax error, this part of the program won't be reached due to compilation failure.
    // However, it's included for completeness as per the prompt's requirements for a "complete C++ program".
    // The actual execution for a syntax error would halt at compilation.
    // To avoid issues with variable-length arrays in older C++ standards,
    // we use fixed-size arrays in main and pass pointers.
    int result = linear_search(arr, size, target);
    std::cout << "Test " << test_num << ": ";
    if (result == expected) {
        std::cout << "PASSED" << std::endl;
    } else {
        std::cout << "FAILED (Expected: " << expected << ", Got: " << result << ")" << std::endl;
    }
}

int main() {
    // Test cases
    int arr1[] = {10, 20, 30, 40, 50};
    run_test(arr1, 5, 10, 0, 1);

    int arr2[] = {10, 20, 30, 40, 50};
    run_test(arr2, 5, 30, 2, 2);

    int arr3[] = {10, 20, 30, 40, 50};
    run_test(arr3, 5, 50, 4, 3);

    int arr4[] = {10, 20, 30, 40, 50};
    run_test(arr4, 5, 60, -1, 4);

    // Note: Passing an empty array to a function expecting int arr[] is technically UB in C-style arrays
    // if size is 0 and arr is not null. For simplicity, we assume arr is valid for size > 0.
    // For size 0, the loop condition i < size will immediately be false.
    int arr5[] = {}; // Represents an empty array contextually
    run_test(arr5, 0, 10, -1, 5);

    int arr6[] = {77};
    run_test(arr6, 1, 77, 0, 6);

    int arr7[] = {77};
    run_test(arr7, 1, 88, -1, 7);

    int arr8[] = {10, 20, 30, 20, 50};
    run_test(arr8, 5, 20, 1, 8);

    return 0;
}