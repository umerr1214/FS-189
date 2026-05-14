#include <iostream>
#include <numeric> // For std::accumulate (not used directly, but good practice)
#include <limits>  // For std::numeric_limits

template <typename T>
double calculate_average(const T arr[], int size) {
    // Robustness Issue: Does not handle size <= 0 gracefully.
    // If size is 0, this will lead to division by zero, resulting in NaN or a runtime crash.
    // This is a common robustness flaw for array processing functions.

    T sum = 0; // sum of type T, potential for overflow if T is int and numbers are very large
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    // If 'size' is 0, this division will result in NaN (for floating point)
    // or potentially a runtime error/crash (depending on compiler/OS for integer division by zero,
    // though 'sum' is cast to double here).
    return static_cast<double>(sum) / size;
}

int main() {
    // Test cases
    int intArray[] = {1, 2, 3, 4, 5};
    int intArraySize = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "Average of intArray: " << calculate_average(intArray, intArraySize) << std::endl;

    double doubleArray[] = {10.5, 20.5, 30.0};
    int doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    std::cout << "Average of doubleArray: " << calculate_average(doubleArray, doubleArraySize) << std::endl;

    // Robustness issue test case: empty array (size 0)
    // This will likely result in NaN or a program crash due to division by zero.
    int emptyArray[] = {};
    int emptyArraySize = 0;
    std::cout << "Average of emptyArray: " << calculate_average(emptyArray, emptyArraySize) << std::endl;

    return 0;
}