#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Function to check if an array is sorted in ascending order
bool isSorted(int arr[], int size) {
    // Semantic error: Incorrectly trying to determine array size using sizeof inside the function.
    // When an array is passed to a function, it decays into a pointer to its first element.
    // Therefore, `sizeof(arr)` will return the size of a pointer (e.g., 8 bytes on a 64-bit system),
    // not the size of the actual array. `sizeof(arr[0])` will be `sizeof(int)`.
    // This calculation will result in `actual_size` being typically 1 or 2, regardless of the true array size.
    // The `size` parameter, which correctly holds the array's size, is ignored.
    int actual_size = sizeof(arr) / sizeof(arr[0]); 

    if (actual_size <= 1) {
        return true;
    }
    for (int i = 0; i < actual_size - 1; ++i) {
        if (arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true;
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

    // Test case 3: Sorted array - Fails for larger arrays
    int arr3[] = {1, 2, 3, 4};
    int size3 = 4;
    std::cout << "Input: " << array_to_string(arr3, size3) << std::endl;
    print_result("Test 3 (Sorted)", true, isSorted(arr3, size3)); // Will likely be true if actual_size is 2 and arr[0] <= arr[1]

    // Test case 4: Unsorted array (middle) - Might pass incorrectly
    int arr4[] = {1, 3, 2, 4};
    int size4 = 4;
    std::cout << "Input: " << array_to_string(arr4, size4) << std::endl;
    print_result("Test 4 (Unsorted middle)", false, isSorted(arr4, size4)); // Expected false, but might be true if only arr[0], arr[1] checked

    // Test case 5: Unsorted array (descending) - Fails for larger arrays
    int arr5[] = {4, 3, 2, 1};
    int size5 = 4;
    std::cout << "Input: " << array_to_string(arr5, size5) << std::endl;
    print_result("Test 5 (Unsorted descending)", false, isSorted(arr5, size5)); // Expected false, will be false (correct for first two, but still semantic error)

    // Test case 6: Sorted array with duplicates - Fails for larger arrays
    int arr6[] = {1, 1, 2, 3};
    int size6 = 4;
    std::cout << "Input: " << array_to_string(arr6, size6) << std::endl;
    print_result("Test 6 (Sorted with duplicates)", true, isSorted(arr6, size6)); // Will likely be true if actual_size is 2 and arr[0] <= arr[1]

    // Test case 7: Unsorted array with duplicates - Might pass incorrectly
    int arr7[] = {1, 2, 1, 3};
    int size7 = 4;
    std::cout << "Input: " << array_to_string(arr7, size7) << std::endl;
    print_result("Test 7 (Unsorted with duplicates)", false, isSorted(arr7, size7)); // Expected false, but might be true if only arr[0], arr[1] checked

    return 0;
}