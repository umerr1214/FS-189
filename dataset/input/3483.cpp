#include <iostream>
#include <numeric> // Not strictly needed for manual sum, but could be used for std::accumulate
#include <vector>  // For easier array creation in main

// Function to calculate the average of a float array
float calculateAverage(float arr[], int size) {
    if (size <= 0) { // Robustness: Handles empty or invalid size inputs
        return 0.0f; // Conventionally returns 0 for an empty average, preventing division by zero
    }

    float sum = 0.0f; // Clear variable name
    for (int i = 0; i < size; ++i) { // Clear and idiomatic loop structure
        sum += arr[i]; // Efficient summation using compound assignment
    }

    return sum / static_cast<float>(size); // Clear and correct type casting for floating-point division
}

int main() {
    // Test case 1: Normal array
    float data1[] = {10.0f, 20.0f, 30.0f, 40.0f, 50.0f};
    int size1 = sizeof(data1) / sizeof(data1[0]);
    std::cout << "Array 1: {10.0, 20.0, 30.0, 40.0, 50.0}, Size: 5" << std::endl;
    std::cout << "Average: " << calculateAverage(data1, size1) << std::endl; // Expected: 30

    std::cout << "--------------------" << std::endl;

    // Test case 2: Empty array (handled robustly)
    float data2[] = {};
    int size2 = 0;
    std::cout << "Array 2: {}, Size: 0" << std::endl;
    std::cout << "Average: " << calculateAverage(data2, size2) << std::endl; // Expected: 0

    std::cout << "--------------------" << std::endl;

    // Test case 3: Single element array
    float data3[] = {123.45f};
    int size3 = sizeof(data3) / sizeof(data3[0]);
    std::cout << "Array 3: {123.45}, Size: 1" << std::endl;
    std::cout << "Average: " << calculateAverage(data3, size3) << std::endl; // Expected: 123.45

    std::cout << "--------------------" << std::endl;

    // Test case 4: Array with negative numbers
    float data4[] = {-10.0f, 0.0f, 10.0f};
    int size4 = sizeof(data4) / sizeof(data4[0]);
    std::cout << "Array 4: {-10.0, 0.0, 10.0}, Size: 3" << std::endl;
    std::cout << "Average: " << calculateAverage(data4, size4) << std::endl; // Expected: 0

    return 0;
}