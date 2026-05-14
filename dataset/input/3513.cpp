#include <iostream>

int main() {
    // Declare and initialize a 1D integer array
    const int SIZE = 5;
    int arr[SIZE] = {10, 20, 30, 40, 50}; // Sum should be 150

    long long sum = 0; // Use long long for sum to prevent overflow with larger arrays/values

    // Calculate the sum using pointer arithmetic
    // Iterate from the beginning of the array to one element past the end
    for (int* ptr = arr; ptr < arr + SIZE; ++ptr) {
        sum += *ptr; // Dereference the current pointer and add to sum
    }

    // Print the sum
    std::cout << "Sum of array elements: " << sum << std::endl;

    return 0;
}