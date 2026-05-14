#include <iostream>

int linear_search(int arr[], int size, int target) {
    // Semantic error: The loop condition `i <= size` causes an out-of-bounds array access
    // when `i` becomes equal to `size`. Valid indices are 0 to size-1.
    for (int i = 0; i <= size; ++i) { 
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void run_test(int arr[], int size, int target, int expected, int test_num) {
    // Note: Semantic errors like out-of-bounds access lead to undefined behavior.
    // The program might crash, produce incorrect results, or appear to work correctly
    // depending on the compiler, environment, and specific inputs.
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
    run_test(arr1, 5, 10, 0, 1); // Correct. Returns before UB.

    int arr2[] = {10, 20, 30, 40, 50};
    run_test(arr2, 5, 30, 2, 2); // Correct. Returns before UB.

    int arr3[] = {10, 20, 30, 40, 50};
    run_test(arr3, 5, 50, 4, 3); // Correct. Returns before UB.

    int arr4[] = {10, 20, 30, 40, 50};
    run_test(arr4, 5, 60, -1, 4); // Will likely cause UB when i=5, accessing arr[5].

    // For size 0, the loop condition `i <= size` means `i <= 0`.
    // The loop runs for i=0, accessing arr[0], which is out of bounds for an empty array.
    int arr5[] = {}; 
    run_test(arr5, 0, 10, -1, 5); // Will cause UB immediately.

    int arr6[] = {77};
    run_test(arr6, 1, 77, 0, 6); // Correct. Returns before UB.

    int arr7[] = {77};
    run_test(arr7, 1, 88, -1, 7); // Will likely cause UB when i=1, accessing arr[1].

    int arr8[] = {10, 20, 30, 20, 50};
    run_test(arr8, 5, 20, 1, 8); // Correct. Returns before UB.

    return 0;
}