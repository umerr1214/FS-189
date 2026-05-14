#include <iostream>

// Function template with a potential robustness issue:
// The return type (T) and the sum variable's type (T) are the same as the array elements.
// This can lead to integer overflow if the sum of elements exceeds the maximum value
// representable by type T, especially for integral types like 'int'.
template <typename T>
T arraySum(T arr[], int size) {
    T sum = 0; // The sum variable has the same type as array elements
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    // Test case 1: Demonstrates integer overflow for int type
    // The sum (2,000,000,000 + 1,500,000,000 + 1,000,000,000 = 4,500,000,000)
    // exceeds the maximum value of a 32-bit signed int (approx. 2.1 billion).
    int arr1[] = {2000000000, 1500000000, 1000000000};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Sum of arr1 (int, expected 4500000000): " << arraySum(arr1, size1) << std::endl;

    // Test case 2: Works correctly for smaller sums within int range
    int arr2[] = {10, 20, 30};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Sum of arr2 (int, expected 60): " << arraySum(arr2, size2) << std::endl;

    // Test case 3: Double array (no overflow issue with typical double range)
    double arr3[] = {1.5, 2.5, 3.0};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "Sum of arr3 (double, expected 7.0): " << arraySum(arr3, size3) << std::endl;

    return 0;
}