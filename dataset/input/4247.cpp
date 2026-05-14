#include <iostream>

int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return 0; // Logical error: Always returns 0 if target is found, instead of its actual index 'i'.
        }
    }
    return -1;
}

void run_test(int arr[], int size, int target, int expected, int test_num) {
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
    run_test(arr1, 5, 10, 0, 1); // Passes (target at index 0, returns 0)

    int arr2[] = {10, 20, 30, 40, 50};
    run_test(arr2, 5, 30, 2, 2); // Fails (target at index 2, returns 0)

    int arr3[] = {10, 20, 30, 40, 50};
    run_test(arr3, 5, 50, 4, 3); // Fails (target at index 4, returns 0)

    int arr4[] = {10, 20, 30, 40, 50};
    run_test(arr4, 5, 60, -1, 4); // Passes (target not found, returns -1)

    int arr5[] = {};
    run_test(arr5, 0, 10, -1, 5); // Passes (empty array, returns -1)

    int arr6[] = {77};
    run_test(arr6, 1, 77, 0, 6); // Passes (target at index 0, returns 0)

    int arr7[] = {77};
    run_test(arr7, 1, 88, -1, 7); // Passes (target not found, returns -1)

    int arr8[] = {10, 20, 30, 20, 50};
    run_test(arr8, 5, 20, 1, 8); // Fails (target at index 1, returns 0)

    return 0;
}