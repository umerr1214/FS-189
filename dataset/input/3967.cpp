#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed, but common for array operations

// Function definition - DOES NOT HANDLE size <= 0
// This version has a robustness flaw: it accesses arr[0] without checking if size > 0.
// If an empty array (size = 0) is passed, this will result in an out-of-bounds access
// or segmentation fault.
void analyzeArray(const int* arr, int size, int& minVal, int& maxVal) {
    // CRITICAL ROBUSTNESS FLAW: Accesses arr[0] without checking if size > 0.
    // If 'size' is 0, 'arr' will be nullptr (from std::vector::data() on an empty vector),
    // and dereferencing arr[0] will cause a segmentation fault.
    minVal = arr[0]; 
    maxVal = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
}

int main() {
    // Demonstrate with a normal array
    std::vector<int> arr_vec1 = {5, 1, 9, 3, 7};
    int size1 = arr_vec1.size();
    int min1_val, max1_val; // Values will be set by the function

    std::cout << "Demonstration 1: Normal array" << std::endl;
    analyzeArray(arr_vec1.data(), size1, min1_val, max1_val);
    std::cout << "Array: {5, 1, 9, 3, 7}, Size: " << size1 << std::endl;
    std::cout << "Min: " << min1_val << ", Max: " << max1_val << std::endl;
    std::cout << "---" << std::endl;

    // Demonstrate the robustness issue: call with an empty array
    std::vector<int> arr_vec2; // An empty vector, size will be 0
    int size2 = arr_vec2.size();
    int min2_val = 0, max2_val = 0; // Initialize to avoid garbage values if not overwritten

    std::cout << "Demonstration 2: Empty array (EXPECTED CRASH/UNDEFINED BEHAVIOR)" << std::endl;
    std::cout << "Attempting to analyze an empty array. This function is not robust and should crash:" << std::endl;
    analyzeArray(arr_vec2.data(), size2, min2_val, max2_val); // <-- CRASH/UNDEFINED BEHAVIOR EXPECTED HERE

    // These lines may not be reached if a crash occurs.
    std::cout << "Min: " << min2_val << ", Max: " << max2_val << std::endl;

    return 0;
}