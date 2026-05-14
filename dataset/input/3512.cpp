#include <iostream>

int main() {
    // Declare and initialize a 1D integer array
    const int SIZE = 5;
    int arr[SIZE] = {10, 20, 30, 40, 50}; // Sum should be 150

    long long sum = 0; // Use long long for sum to prevent overflow with larger arrays/values

    // Calculate the sum using pointer arithmetic
    // Readability/Efficiency Issue: Repeated calculation of end_ptr and less idiomatic pointer usage
    int* current_ptr = arr;
    int* end_ptr = arr + SIZE; // Calculate end_ptr once

    while (current_ptr != end_ptr) { // Loop until current_ptr reaches one past the last element
        sum += *current_ptr; // Dereference current pointer
        // Instead of directly incrementing current_ptr, it recalculates it using an offset
        // This is less efficient and less idiomatic than simply `current_ptr++`
        current_ptr = arr + (current_ptr - arr + 1); 
    }

    // Print the sum
    std::cout << "Sum of array elements: " << sum << std::endl;

    return 0;
}