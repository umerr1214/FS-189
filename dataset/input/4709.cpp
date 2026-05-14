#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Function to check if an array is sorted in ascending order
bool isSorted(int arr[], int size) {
    if (size <= 1) {
        return true;
    }
    // Logical error: The function only checks the first two elements.
    // It should iterate through the entire array comparing arr[i] with arr[i+1].
    if (arr[0] > arr[1]) {
        return false;
    }
    return true; // Incorrectly assumes the rest of the array is sorted if the first two elements are.
}

// Helper function to print test results
void print_result(const std::string& test_name, bool expected, bool actual) {
    std::cout << test_name << ": ";
    if (actual == expected) {
        std::cout << "PASS";
    } else {
        std::cout << "FAIL (Expected: " << (expected ? "true" : "false") << ", Got: " << (actual ? "true" : "false") << ")";
    }
    std::cout << std::endl;
}

// Helper function to convert array to string for input display
std::string array_to_string(const int arr[], int size) {
    std::ostringstream oss;
    oss << "[";
    for (int i = 0; i < size; ++i) {
        oss << arr[i];
        if (i < size - 1) {
            oss << ", ";
        }
    }
    oss << "]";
    return oss.str();
}

int main() {
    // Test case 1: Empty array
    int arr1[] = {};
    int size1 = 0;
    std::cout << "Input: " << array_to_string(arr1, size1) << std::endl;
    print_result("Test 1 (Empty)", true, isSorted(arr1, size1));

    // Test case 2: Single element array
    int arr2[] = {5};
    int size2 = 1;
    std::cout << "Input: " << array_to_string(arr2, size2) << std::endl;
    print_result("Test 2 (Single)", true, isSorted(arr2, size2));

    // Test case 3: Sorted array
    int arr3[] = {1, 2, 3, 4};
    int size3 = 4;
    std::cout << "Input: " << array_to_string(arr3, size3) << std::endl;
    print_result("Test 3 (Sorted)", true, isSorted(arr3, size3));

    // Test case 4: Unsorted array (middle) - Fails here
    int arr4[] = {1, 3, 2, 4};
    int size4 = 4;
    std::cout << "Input: " << array_to_string(arr4, size4) << std::endl;
    print_result("Test 4 (Unsorted middle)", false, isSorted(arr4, size4)); // Expected false, will be true

    // Test case 5: Unsorted array (descending) - Fails here
    int arr5[] = {4, 3, 2, 1};
    int size5 = 4;
    std::cout << "Input: " << array_to_string(arr5, size5) << std::endl;
    print_result("Test 5 (Unsorted descending)", false, isSorted(arr5, size5)); // Expected false, will be false (correct for first two, but still logical error)

    // Test case 6: Sorted array with duplicates
    int arr6[] = {1, 1, 2, 3};
    int size6 = 4;
    std::cout << "Input: " << array_to_string(arr6, size6) << std::endl;
    print_result("Test 6 (Sorted with duplicates)", true, isSorted(arr6, size6));

    // Test case 7: Unsorted array with duplicates - Fails here
    int arr7[] = {1, 2, 1, 3};
    int size7 = 4;
    std::cout << "Input: " << array_to_string(arr7, size7) << std::endl;
    print_result("Test 7 (Unsorted with duplicates)", false, isSorted(arr7, size7)); // Expected false, will be true

    return 0;
}