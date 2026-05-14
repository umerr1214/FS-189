#include <iostream>
#include <array>    // Using std::array for fixed-size array
#include <limits>   // For std::numeric_limits

int main() {
    const int ARY_SZ = 5; // Array size constant
    std::array<int, ARY_SZ> my_arr; // Declare std::array

    std::cout << "Enter " << ARY_SZ << " integer values:\n";

    // Input values into the array
    for (int i = 0; i < ARY_SZ; ++i) {
        std::cout << "Value " << i + 1 << ": ";
        std::cin >> my_arr[i];
    }

    // Readability / Efficiency Issue: Finding min and max in two separate loops.
    // This requires iterating over the array twice, which is less efficient
    // than finding both in a single pass. While for a small array of size 5
    // the performance difference is negligible, it's a less efficient approach.
    // Also, variable names like 'ARY_SZ' could be 'ARRAY_SIZE' for better readability.

    int mx_val = std::numeric_limits<int>::min(); // Initialize max to smallest possible int
    for (int i = 0; i < ARY_SZ; ++i) {
        if (my_arr[i] > mx_val) {
            mx_val = my_arr[i];
        }
    }

    int mn_val = std::numeric_limits<int>::max(); // Initialize min to largest possible int
    for (int i = 0; i < ARY_SZ; ++i) {
        if (my_arr[i] < mn_val) {
            mn_val = my_arr[i];
        }
    }

    std::cout << "Largest: " << mx_val << std::endl; // Using std::endl which flushes, less efficient in loop
    std::cout << "Smallest: " << mn_val << std::endl; // Using std::endl

    return 0;
}