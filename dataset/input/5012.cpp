#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Function with readability and efficiency issues
void findMinMax(int arr[], int size, int* minPtr, int* maxPtr) {
    // Handle null pointers (robustness, not the primary issue for this category)
    if (minPtr == nullptr || maxPtr == nullptr) {
        return;
    }

    // Handle empty array (robustness, not the primary issue for this category)
    if (size <= 0) {
        // For an empty array, set to a default value (e.g., 0) as no min/max exist.
        // This is a chosen behavior for the function's contract.
        *minPtr = 0;
        *maxPtr = 0;
        return;
    }

    // Efficiency Issue: Performs two separate passes over the array.
    // A single pass is sufficient to find both min and max.

    // First pass to find the minimum.
    int currentMinVal = arr[0];
    for (int k = 1; k < size; ++k) { // Using 'k' as loop variable
        if (arr[k] < currentMinVal) {
            currentMinVal = arr[k];
        }
    }
    *minPtr = currentMinVal;

    // Second pass to find the maximum.
    int currentMaxVal = arr[0];
    for (int idx = 1; idx < size; ++idx) { // Using 'idx' as loop variable
        if (arr[idx] > currentMaxVal) {
            currentMaxVal = arr[idx];
        }
    }
    *maxPtr = currentMaxVal;

    // Readability Issue (minor): Using different loop variable names (k, idx) for
    // essentially identical loops without clear justification can slightly reduce
    // consistency and readability. Also, verbose variable names like `currentMinVal`
    // could be shortened to `min_val` or `min_v` for conciseness.
}

// Helper to run a test case and format output
std::string run_test(const std::vector<int>& data) {
    int minVal, maxVal;
    findMinMax(const_cast<int*>(data.data()), data.size(), &minVal, &maxVal);
    std::stringstream ss;
    ss << "Min: " << minVal << ", Max: " << maxVal;
    return ss.str();
}

int main() {
    std::cout << "Test Cases for findMinMax (Readability/Efficiency Issue):" << std::endl;

    // Test Case 1: Empty array
    std::vector<int> arr0 = {};
    std::cout << "Array: {} -> " << run_test(arr0) << std::endl;

    // Test Case 2: Single element array
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