#include <iostream>
#include <vector>

int main() {
    // Initialize a 1D integer array with 10 elements
    int arr[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}; // Array containing only even numbers

    long long sum_even = 0;
    long long product_odd = 0; // Robustness Issue: Initialized to 0. Should be 1 for empty product.

    for (int i = 0; i < 10; ++i) {
        if (arr[i] % 2 == 0) {
            sum_even += arr[i];
        } else {
            // This logic correctly handles the first odd number if product_odd starts at 0,
            // but if no odd numbers are found, product_odd remains 0, which is mathematically
            // incorrect for an empty product (should be 1).
            if (product_odd == 0) {
                product_odd = arr[i];
            } else {
                product_odd *= arr[i];
            }
        }
    }

    // Due to the initialization of product_odd to 0 and the array containing no odd numbers,
    // the output for product of odd numbers will be 0, instead of the mathematically correct 1.
    std::cout << "Sum of even numbers: " << sum_even << std::endl;
    std::cout << "Product of odd numbers: " << product_odd << std::endl;

    return 0;
}