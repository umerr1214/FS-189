#include <iostream>
#include <vector> // Not directly used in template, but common for array-like structures
#include <numeric> // Included, but we'll use a custom, less efficient loop

template <typename T>
double calculate_average(const T arr[], int size) {
    if (size <= 0) {
        return 0.0; // Handles empty array correctly
    }

    // Readability / Efficiency Issue:
    // 1. Using 'long double' for the sum type is often overkill and can be less efficient
    //    than 'double' on many architectures, especially when 'T' is 'int' or 'float'.
    // 2. The manual 'while' loop with pointer arithmetic and a decrementing counter is
    //    less idiomatic and potentially less readable than a simple indexed 'for' loop
    //    or `std::accumulate` for this common task.
    long double current_sum = 0.0;
    const T* current_ptr = arr;
    int remaining_elements = size;

    while (remaining_elements > 0) {
        current_sum += *current_ptr;
        current_ptr++;
        remaining_elements--;
    }

    // Cast the final average to double
    return static_cast<double>(current_sum / size);
}

int main() {
    // Test cases
    int intArray[] = {1, 2, 3, 4, 5};
    int intArraySize = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "Average of intArray: " << calculate_average(intArray, intArraySize) << std::endl;

    double doubleArray[] = {10.5, 20.5, 30.0};
    int doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    std::cout << "Average of doubleArray: " << calculate_average(doubleArray, doubleArraySize) << std::endl;

    // Edge case: empty array (handled correctly here)
    int emptyArray[] = {};
    int emptyArraySize = 0;
    std::cout << "Average of emptyArray: " << calculate_average(emptyArray, emptyArraySize) << std::endl;

    // Test with large numbers that might benefit from long double's range,
    // but still an inefficient choice for sum type if not strictly needed.
    long long largeNumArray[] = {1000000000000000000LL, 2000000000000000000LL};
    int largeNumArraySize = sizeof(largeNumArray) / sizeof(largeNumArray[0]);
    std::cout << "Average of largeNumArray: " << calculate_average(largeNumArray, largeNumArraySize) << std::endl;

    return 0;
}