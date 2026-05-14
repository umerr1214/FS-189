#include <iostream>
#include <cmath> // For std::abs in correctness check

// Semantic Error: Explicitly casts sum to int before returning, leading to precision loss for floating-point types
template <typename T>
T arraySum(const T arr[], int size) {
    T sum = T(); // Initialize with default constructor (0 for numeric types)
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    // Semantic Error: The result is cast to int, losing precision for floating-point types.
    // This int value is then implicitly converted back to T (e.g., double) for the return.
    return static_cast<int>(sum);
}

int main() {
    // Test case 1: int array (works correctly as int to int cast is fine)
    int intArray[] = {1, 2, 3, 4, 5};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    int actualIntSum = arraySum(intArray, intSize);
    int expectedIntSum = 15;
    std::cout << "Int Array: {1, 2, 3, 4, 5}" << std::endl;
    std::cout << "Actual Sum (Semantic Error): " << actualIntSum << " (Expected: " << expectedIntSum << ")" << std::endl;
    std::cout << "Result: " << (actualIntSum == expectedIntSum ? "Correct" : "Incorrect") << std::endl; // Should be "Correct"

    std::cout << std::endl;

    // Test case 2: double array (shows precision loss)
    double doubleArray[] = {1.1, 2.2, 3.3};
    int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    double actualDoubleSum = arraySum(doubleArray, doubleSize); // 6.6 gets truncated to 6, then returned as 6.0
    double expectedDoubleSum = 6.6;
    std::cout << "Double Array: {1.1, 2.2, 3.3}" << std::endl;
    std::cout << "Actual Sum (Semantic Error): " << actualDoubleSum << " (Expected: " << expectedDoubleSum << ")" << std::endl;
    // Using a small epsilon for double comparison
    std::cout << "Result: " << (std::abs(actualDoubleSum - expectedDoubleSum) < 0.0001 ? "Correct" : "Correctly identified error") << std::endl; // Should be "Correctly identified error"

    return 0;
}