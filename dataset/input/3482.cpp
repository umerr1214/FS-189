#include <iostream>
#include <vector> // Not strictly necessary for fixed-size arrays, but useful for context

// Function to calculate the average of a float array
float calculateAverage(float a[], int n) { // Readability Issue: Poor variable names (a for arr, n for size)
    float s = 0.0f; // Readability Issue: Poor variable name (s for sum)
    int i = 0; // Readability Issue: Poor variable name (i for index/counter)
    while (i < n) { // Efficiency/Readability Issue: Using while loop with manual increment, less idiomatic than for loop for array iteration
        s = s + a[i]; // Efficiency Issue: Less efficient than s += a[i]
        i++;
    }
    // Correctness: Assumes n > 0. If n == 0, it would lead to division by zero,
    // but for 'Readability/Efficiency Issue' category with correctness=9, we assume valid inputs (n > 0).
    return s / static_cast<float>(n); // Correct calculation, but overall style is suboptimal
}

int main() {
    // Test case 1: Normal array
    float data1[] = {10.0f, 20.0f, 30.0f, 40.0f, 50.0f};
    int size1 = sizeof(data1) / sizeof(data1[0]);
    std::cout << "Array 1: {10.0, 20.0, 30.0, 40.0, 50.0}, Size: 5" << std::endl;
    std::cout << "Average: " << calculateAverage(data1, size1) << std::endl; // Expected: 30

    std::cout << "--------------------" << std::endl;

    // Test case 2: Different normal array
    float data2[] = {1.5f, 2.5f, 3.5f};
    int size2 = sizeof(data2) / sizeof(data2[0]);
    std::cout << "Array 2: {1.5, 2.5, 3.5}, Size: 3" << std::endl;
    std::cout << "Average: " << calculateAverage(data2, size2) << std::endl; // Expected: 2.5

    std::cout << "--------------------" << std::endl;

    // Test case 3: Single element array
    float data3[] = {99.9f};
    int size3 = sizeof(data3) / sizeof(data3[0]);
    std::cout << "Array 3: {99.9}, Size: 1" << std::endl;
    std::cout << "Average: " << calculateAverage(data3, size3) << std::endl; // Expected: 99.9

    return 0;
}