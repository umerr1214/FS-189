#include <iostream>

// Function signature: double calculate_average(const int arr[], int size)
double calculate_average(const int arr[], int size) {
    if (size <= 0) {
        return 0.0;
    }
    // Logical Error: 'total' is an int. The division 'total / size' will perform
    // integer division, truncating any fractional part before returning a double.
    // This leads to incorrect averages for non-integer results.
    int total = 0; 
    for (int i = 0; i < size; ++i) {
        total += arr[i];
    }
    return total / size; // Integer division happens here
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = 5;
    std::cout << "Average of {1, 2, 3, 4, 5}: " << calculate_average(arr1, size1) << std::endl; // Expected: 3.0, Actual: 3.0

    int arr2[] = {10};
    int size2 = 1;
    std::cout << "Average of {10}: " << calculate_average(arr2, size2) << std::endl; // Expected: 10.0, Actual: 10.0

    int arr3[] = {};
    int size3 = 0;
    std::cout << "Average of {}: " << calculate_average(arr3, size3) << std::endl; // Expected: 0.0, Actual: 0.0

    int arr4[] = {1, 2, 4};
    int size4 = 3;
    std::cout << "Average of {1, 2, 4}: " << calculate_average(arr4, size4) << std::endl; // Expected: 2.333..., Actual: 2.0

    int arr5[] = {1, 2, 3, 4};
    int size5 = 4;
    std::cout << "Average of {1, 2, 3, 4}: " << calculate_average(arr5, size5) << std::endl; // Expected: 2.5, Actual: 2.0

    return 0;
}