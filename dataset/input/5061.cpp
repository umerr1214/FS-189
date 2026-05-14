#include <iostream>
#include <numeric> // Not strictly needed for manual loop, but good practice for std::accumulate

// Function template to sum elements of an array.
// Uses `long double` for the return type and sum variable. This is a robust choice
// as `long double` typically offers the widest range and precision among floating-point types,
// effectively preventing overflow for common integer types and maintaining precision for
// floating-point numbers.
template <typename T>
long double arraySum(const T arr[], int size) {
    long double sum = 0.0L; // Initialize sum with a wide, robust type
    for (int i = 0; i < size; ++i) {
        sum += arr[i]; // Elements are implicitly converted to long double for summation
    }
    return sum;
}

int main() {
    // Test case 1: Integer array
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Sum of arr1 (int, expected 15.0): " << arraySum(arr1, size1) << std::endl;

    // Test case 2: Double array
    double arr2[] = {10.5, 20.0, -5.5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Sum of arr2 (double, expected 25.0): " << arraySum(arr2, size2) << std::endl;

    // Test case 3: Long array with negative numbers
    long arr3[] = {-100L, 50L, 20L};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "Sum of arr3 (long, expected -30.0): " << arraySum(arr3, size3) << std::endl;

    // Test case 4: Empty array - should return 0
    int arr4[] = {};
    int size4 = 0;
    std::cout << "Sum of arr4 (empty, expected 0.0): " << arraySum(arr4, size4) << std::endl;

    // Test case 5: Single element array
    float arr5[] = {100.0f};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    std::cout << "Sum of arr5 (float, expected 100.0): " << arraySum(arr5, size5) << std::endl;

    // Test case 6: Array with large long long values to ensure robustness against overflow
    long long arr6[] = {2000000000000000000LL, 3000000000000000000LL, 1000000000000000000LL};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    std::cout << "Sum of arr6 (long long, expected 6000000000000000000.0): " << arraySum(arr6, size6) << std::endl;

    return 0;
}