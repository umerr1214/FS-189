#include <iostream>

// Function signature: double calculate_average(const int arr[], int size)
double calculate_average(const int arr[], int size) {
    if (size <= 0) {
        return 0.0;
    }
    double total = 0.0;
    // Semantic Error: The loop condition `i <= size` causes an out-of-bounds access
    // when `i` equals `size`. Arrays are 0-indexed, so valid indices are `0` to `size - 1`.
    // Accessing `arr[size]` results in undefined behavior and an incorrect sum.
    for (int i = 0; i <= size; ++i) { 
        total += arr[i]; // Accesses arr[size] on the last iteration, which is out of bounds.
                         // This adds a garbage value or causes a crash, leading to an incorrect total.
    }
    // Even if it doesn't crash, the 'total' will be incorrect because it sums 'size + 1' elements.
    return total / static_cast<double>(size); 
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5}; // size 5. Loop accesses arr[0]...arr[5]. arr[5] is out of bounds.
    int size1 = 5;
    std::cout << "Average of {1, 2, 3, 4, 5}: " << calculate_average(arr1, size1) << std::endl;

    int arr2[] = {10}; // size 1. Loop accesses arr[0], arr[1]. arr[1] is out of bounds.
    int size2 = 1;
    std::cout << "Average of {10}: " << calculate_average(arr2, size2) << std::endl;

    int arr3[] = {}; // size 0. Handled by if (size <= 0) check.
    int size3 = 0;
    std::cout << "Average of {}: " << calculate_average(arr3, size3) << std::endl;

    int arr4[] = {1, 2, 4}; // size 3. Loop accesses arr[0]...arr[3]. arr[3] is out of bounds.
    int size4 = 3;
    std::cout << "Average of {1, 2, 4}: " << calculate_average(arr4, size4) << std::endl;

    return 0;
}