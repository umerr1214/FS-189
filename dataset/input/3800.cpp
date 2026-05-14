#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Function with readability issues: poor variable names, lack of comments, and use of goto
int linearSearch(const int* const a, int s, int t) { // 'a' for array, 's' for size, 't' for target - poor naming
    // Lack of comments to explain the function's purpose or logic.
    int idx = -1; // 'idx' is not descriptive (e.g., 'foundIndex')
    int c = 0;    // 'c' is a poor choice for loop counter (e.g., 'i' or 'currentIndex')
    while (c < s) {
        if (*(a + c) == t) { // Using pointer arithmetic instead of simpler 'a[c]' for no benefit, reducing readability
            idx = c;
            goto found_label; // Using goto makes control flow harder to follow
        }
        c++;
    }
    
found_label: // Label for the goto statement
    return idx;
}

// Helper to print array content for test output
std::string array_to_string(const int* arr, int size) {
    std::ostringstream oss;
    oss << "[";
    if (arr == nullptr && size > 0) { 
        oss << "nullptr (size " << size << ")"; 
    } else {
        for (int i = 0; i < size; ++i) {
            oss << arr[i] << (i == size - 1 ? "" : ", ");
        }
    }
    oss << "]";
    return oss.str();
}

int main() {
    std::cout << "Running tests for linearSearch function:" << std::endl;

    // Test Case 1: Standard array, target found in middle
    int arr1[] = {10, 20, 30, 40, 50};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int target1 = 30;
    std::cout << "Searching for " << target1 << " in " << array_to_string(arr1, size1) << ": " << linearSearch(arr1, size1, target1) << std::endl;

    // Test Case 2: Standard array, target not found
    int target2 = 60;
    std::cout << "Searching for " << target2 << " in " << array_to_string(arr1, size1) << ": " << linearSearch(arr1, size1, target2) << std::endl;

    // Test Case 3: Target at the beginning
    int target3 = 10;
    std::cout << "Searching for " << target3 << " in " << array_to_string(arr1, size1) << ": " << linearSearch(arr1, size1, target3) << std::endl;

    // Test Case 4: Target at the end
    int target4 = 50;
    std::cout << "Searching for " << target4 << " in " << array_to_string(arr1, size1) << ": " << linearSearch(arr1, size1, target4) << std::endl;

    // Test Case 5: Single element array, target found
    int arr2[] = {5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int target5 = 5;
    std::cout << "Searching for " << target5 << " in " << array_to_string(arr2, size2) << ": " << linearSearch(arr2, size2, target5) << std::endl;

    // Test Case 6: Single element array, target not found
    int target6 = 10;
    std::cout << "Searching for " << target6 << " in " << array_to_string(arr2, size2) << ": " << linearSearch(arr2, size2, target6) << std::endl;

    // Test Case 7: Empty array (size 0)
    int arr3[] = {}; 
    int size3 = 0;
    int target7 = 100;
    std::cout << "Searching for " << target7 << " in " << array_to_string(arr3, size3) << ": " << linearSearch(arr3, size3, target7) << std::endl;

    // Test Case 8: Array with duplicate elements, target found (first occurrence)
    int arr4[] = {7, 7, 7, 7};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    int target8 = 7;
    std::cout << "Searching for " << target8 << " in " << array_to_string(arr4, size4) << ": " << linearSearch(arr4, size4, target8) << std::endl;

    // Test Case 9: Array with duplicate elements, target not found
    int target9 = 8;
    std::cout << "Searching for " << target9 << " in " << array_to_string(arr4, size4) << ": " << linearSearch(arr4, size4, target9) << std::endl;

    return 0;
}