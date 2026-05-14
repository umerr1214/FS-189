#include <iostream>

int main() {
    // Declare and initialize a 1D integer array
    const int SIZE = 5;
    int arr[SIZE] = {10, 20, 30, 40, 50}; // Sum should be 150

    long long sum = 0; // Use long long for sum to prevent overflow with larger arrays/values
    int* ptr = arr;

    // Calculate the sum using pointer arithmetic
    // Robustness Issue: Off-by-one error, iterates one element past the end of the array
    for (int i = 0; i <= SIZE; ++i) { // Loop condition should be i < SIZE
        sum += *(ptr + i); // Accesses arr[SIZE] when i == SIZE, leading to undefined behavior
    }

    // Print the sum
    std::cout << "Sum of array elements: " << sum << std::endl;

    return 0;
}