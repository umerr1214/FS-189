#include <iostream>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    int* ptr = arr; // Pointer to the first element

    // Logical Error: The loop condition 'i < size - 1' causes the program
    // to iterate one time less than required, skipping the last element.
    // It should be 'i < size'.
    for (int i = 0; i < size - 1; ++i) {
        sum += *ptr;
        ptr++;
    }

    std::cout << "Sum of array elements: " << sum << std::endl; // Expected: 15, Actual: 10

    return 0;
}