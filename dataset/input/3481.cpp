#include <iostream>
#include <vector> // Not strictly necessary for fixed-size arrays, but useful for context

// Function to calculate the average of a float array
float calculateAverage(float arr[], int size) {
    float sum = 0.0f;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    // Robustness Issue: Does not explicitly handle size == 0.
    // If size is 0, sum will be 0.0f, leading to 0.0f / 0.0f which results in NaN (Not a Number).
    // A robust solution would check `if (size <= 0)` before division.
    return sum / static_cast<float>(size);
}

int main() {
    // Test case 1: Normal array
    float data1[] = {10.0f, 20.0f, 30.0f, 40.0f, 50.0f};
    int size1 = sizeof(data1) / sizeof(data1[0]);
    std::cout << "Array 1: {10.0, 20.0, 30.0, 40.0, 50.0}, Size: 5" << std::endl;
    std::cout << "Average: " << calculateAverage(data1, size1) << std::endl; // Expected: 30

    std::cout << "--------------------" << std::endl;

    // Test case 2: Empty array (leads to NaN output due to 0/0)
    float data2[] = {};
    int size2 = 0;
    std::cout << "Array 2: {}, Size: 0" << std::endl;
    std::cout << "Average: " << calculateAverage(data2, size2) << std::endl; // Expected: nan

    std::cout << "--------------------" << std::endl;

    // Test case 3: Single element array
    float data3[] = {123.45f};
    int size3 = sizeof(data3) / sizeof(data3[0]);
    std::cout << "Array 3: {123.45}, Size: 1" << std::endl;
    std::cout << "Average: " << calculateAverage(data3, size3) << std::endl; // Expected: 123.45

    return 0;
}