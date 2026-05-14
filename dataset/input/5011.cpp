#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Function with a robustness issue:
// It does not explicitly define behavior for output pointers when the array is empty.
// If size <= 0, the pointers minPtr and maxPtr are left untouched.
// This means the variables they point to (e.g., minVal, maxVal in main) will retain
// their initial values (or be uninitialized if not explicitly set), which is
// incorrect behavior for an empty array where no min/max can be found.
void findMinMax(int arr[], int size, int* minPtr, int* maxPtr) {
    // Assume minPtr and maxPtr are valid (not nullptr) for the purpose of this specific issue.
    // The robustness issue here is the lack of defined output for size <= 0.
    if (size <= 0) {
        // Robustness Issue: For an empty array, the function returns without modifying
        // minPtr and maxPtr. This leaves the caller's variables uninitialized
        // or with their previous values, which is not a clear or correct contract
        // for "storing the minimum and maximum values".
        // A robust solution would set them to sentinel values (e.g., INT_MAX/INT_MIN)
        // or a specific error code.
        return;
    }

    int currentMin = arr[0];
    int currentMax = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] < currentMin) {
            currentMin = arr[i];
        }
        if (arr[i] > currentMax) {
            currentMax = arr[i];
        }
    }

    *minPtr = currentMin;
    *maxPtr = currentMax;
}

// Helper to run a test case and format output
std::string run_test(const std::vector<int>& data) {
    int minVal = 0; // Initialize to a default value.
    int maxVal = 0; // If findMinMax doesn't assign, these values will remain.
    
    // For the robustness issue, if data is empty, findMinMax will return without
    // assigning, leaving minVal and maxVal as 0. This is the incorrect behavior
    // we want to demonstrate.
    findMinMax(const_cast<int*>(data.data()), data.size(), &minVal, &maxVal);
    
    std::stringstream ss;
    ss << "Min: " << minVal << ", Max: " << maxVal;
    return ss.str();
}

int main() {
    std::cout << "Test Cases for findMinMax (Robustness Issue):" << std::endl;

    // Test Case 1: Empty array (triggers robustness issue - incorrect output for empty array)
    std::vector<int> arr0 = {};
    std::cout << "Array: {} -> " << run_test(arr0) << std::endl;

    // Test Case 2: Single element array (should work correctly)
    std::vector<int> arr1 = {5};
    std::cout << "Array: {5} -> " << run_test(arr1) << std::endl;

    // Test Case 3: Multiple elements (positive)
    std::vector<int> arr2 = {1, 5, 2, 8, 3};
    std::cout << "Array: {1,5,2,8,3} -> " << run_test(arr2) << std::endl;

    // Test Case 4: Multiple elements (negative)
    std::vector<int> arr3 = {-10, -5, -1, -8, -3};
    std::cout << "Array: {-10,-5,-1,-8,-3} -> " << run_test(arr3) << std::endl;

    // Test Case 5: Multiple elements (mixed)
    std::vector<int> arr4 = {-5, 0, 5, -10, 10};
    std::cout << "Array: {-5,0,5,-10,10} -> " << run_test(arr4) << std::endl;

    // Test Case 6: All elements same
    std::vector<int> arr5 = {7, 7, 7, 7};
    std::cout << "Array: {7,7,7,7} -> " << run_test(arr5) << std::endl;

    return 0;
}