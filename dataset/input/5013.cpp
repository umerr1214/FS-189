#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits> // For std::numeric_limits

// Correct, robust, and efficient function
void findMinMax(int arr[], int size, int* minPtr, int* maxPtr) {
    // Robustness check 1: Ensure output pointers are valid.
    if (minPtr == nullptr || maxPtr == nullptr) {
        // If pointers are null, we cannot store results.
        // A robust implementation might throw an exception or log an error.
        return;
    }

    // Robustness check 2: Handle empty array gracefully.
    if (size <= 0) {
        // For an empty array, no min/max can be found.
        // Set to sentinel values that clearly indicate "no value found".
        // std::numeric_limits<int>::max() for min means "no smaller value found".
        // std::numeric_limits<int>::min() for max means "no larger value found".
        *minPtr = std::numeric_limits<int>::max();
        *maxPtr = std::numeric_limits<int>::min();
        return;
    }

    // Initialize min and max with the first element.
    // This handles the case of a single-element array correctly.
    int currentMin = arr[0];
    int currentMax = arr[0];

    // Efficiency: Iterate from the second element to find min and max in a single pass.
    for (int i = 1; i < size; ++i) {
        if (arr[i] < currentMin) {
            currentMin = arr[i];
        }
        if (arr[i] > currentMax) {
            currentMax = arr[i];
        }
    }

    // Store the results using the provided pointers.
    *minPtr = currentMin;
    *maxPtr = currentMax;
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
    std::cout << "Test Cases for findMinMax (Correct Version):" << std::endl;

    // Test Case 1: Empty array (handled gracefully with sentinel values)
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