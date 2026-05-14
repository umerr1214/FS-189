#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm> // Required for std::sort
#include <limits>    // Required for std::numeric_limits

int findMin(int arr[], int size) {
    if (size == 0) {
        // Handles empty array to prevent crash from std::vector initialization or arr[0] access.
        // Returns 0, which is incorrect for the problem's intent, similar to robustness issue,
        // but the primary focus here is the inefficiency of the sorting approach.
        return 0;
    }
    // Inefficiency: Sorting the entire array (O(N log N)) is overkill
    // for finding just the minimum, which can be done in a single linear scan (O(N)).
    // Also, copying to a vector adds unnecessary memory and time overhead.
    std::vector<int> temp_arr(arr, arr + size); // Copies the array to a vector
    std::sort(temp_arr.begin(), temp_arr.end()); // Sorts the entire vector
    return temp_arr[0]; // Returns the first element after sorting
}

void runTestCase(const std::vector<int>& arr, int size, int expected) {
    std::ostringstream input_oss;
    input_oss << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        input_oss << arr[i];
        if (i < arr.size() - 1) {
            input_oss << ", ";
        }
    }
    input_oss << "], size: " << size;
    std::string input_str = input_oss.str();

    // Use const_cast to convert const int* from vector::data() to int* for the function signature
    int result = findMin(const_cast<int*>(arr.data()), size);
    
    std::cout << "Input: " << input_str << ", Expected: " << expected << ", Got: " << result << std::endl;
    if (result == expected) {
        std::cout << "  PASS" << std::endl;
    } else {
        std::cout << "  FAIL" << std::endl;
    }
}

int main() {
    std::cout << "Running test cases for findMin:" << std::endl;

    std::vector<int> arr1 = {5, 2, 8, 1, 9};
    runTestCase(arr1, arr1.size(), 1);

    std::vector<int> arr2 = {-10, -3, -15, -7};
    runTestCase(arr2, arr2.size(), -15);

    std::vector<int> arr3 = {0, -5, 10, 3, -1};
    runTestCase(arr3, arr3.size(), -5);

    std::vector<int> arr4 = {7};
    runTestCase(arr4, arr4.size(), 7);

    std::vector<int> arr5 = {4, 4, 4, 4};
    runTestCase(arr5, arr5.size(), 4);

    std::vector<int> arr_empty = {};
    runTestCase(arr_empty, arr_empty.size(), 0); // Expected 0 for empty array in this version

    return 0;
}