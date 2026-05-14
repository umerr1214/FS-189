#include <iostream>
#include <cmath> // For std::abs in correctness check

// Logical Error: Loop iterates one element short, missing the last element
template <typename T>
T arraySum(const T arr[], int size) {
    T sum = T(); // Initialize with default constructor (0 for numeric types)
    for (int i = 0; i < size - 1; ++i) { // Logical Error: Should be 'i < size'
        sum += arr[i];
    }
    return sum;
}

int main() {
    // Test case 1: int array
    int intArray[] = {1, 2, 3, 4, 5};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    int actualIntSum = arraySum(intArray, intSize);
    int expectedIntSum = 15; // Correct sum
    std::cout << "Int Array: {1, 2, 3, 4, 5}" << std::endl;
    std::cout << "Actual Sum (Logical Error): " << actualIntSum << " (Expected: " << expectedIntSum << ")" << std::endl;
    std::cout << "Result: " << (actualIntSum == expectedIntSum ? "Incorrect" : "Correctly identified error") << std::endl; // Should be "Correctly identified error"

    std::cout << std::endl;

    // Test case 2: double array
    double doubleArray[] = {1.1, 2.2, 3.3};
    int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    double actualDoubleSum = arraySum(doubleArray, doubleSize);
    double expectedDoubleSum = 6.6; // Correct sum
    std::cout << "Double Array: {1.1, 2.2, 3.3}" << std::endl;
    std::cout << "Actual Sum (Logical Error): " << actualDoubleSum << " (Expected: " << expectedDoubleSum << ")" << std::endl;
    // Using a small epsilon for double comparison
    std::cout << "Result: " << (std::abs(actualDoubleSum - expectedDoubleSum) < 0.0001 ? "Incorrect" : "Correctly identified error") << std::endl; // Should be "Correctly identified error"

    return 0;
}