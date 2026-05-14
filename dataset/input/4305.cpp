#include <iostream>
#include <numeric> // Required for std::accumulate
#include <vector>  // For driver test cases, not for the template itself

template <typename T>
double calculate_average(const T arr[], int size) {
    if (size <= 0) {
        return 0.0; // Handle empty array or invalid size gracefully
    }

    // Use double for sum to prevent overflow for large integer types and maintain precision.
    // std::accumulate is an efficient, concise, and idiomatic C++ way for summing elements.
    double sum = std::accumulate(arr, arr + size, 0.0);

    return sum / size;
}

int main() {
    // Test cases
    int intArray[] = {1, 2, 3, 4, 5};
    int intArraySize = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "Average of intArray: " << calculate_average(intArray, intArraySize) << std::endl;

    double doubleArray[] = {10.5, 20.5, 30.0};
    int doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    std::cout << "Average of doubleArray: " << calculate_average(doubleArray, doubleArraySize) << std::endl;

    // Test with float array
    float floatArray[] = {1.1f, 2.2f, 3.3f};
    int floatArraySize = sizeof(floatArray) / sizeof(floatArray[0]);
    std::cout << "Average of floatArray: " << calculate_average(floatArray, floatArraySize) << std::endl;

    // Edge case: empty array
    int emptyArray[] = {};
    int emptyArraySize = 0;
    std::cout << "Average of emptyArray: " << calculate_average(emptyArray, emptyArraySize) << std::endl;

    // Test with single element
    int singleElementArray[] = {42};
    int singleElementArraySize = 1;
    std::cout << "Average of singleElementArray: " << calculate_average(singleElementArray, singleElementArraySize) << std::endl;

    // Test with large numbers (long long) to ensure precision and prevent overflow
    long long largeNumArray[] = {1000000000000000000LL, 2000000000000000000LL, 3000000000000000000LL};
    int largeNumArraySize = sizeof(largeNumArray) / sizeof(largeNumArray[0]);
    std::cout << "Average of largeNumArray: " << calculate_average(largeNumArray, largeNumArraySize) << std::endl;

    return 0;
}