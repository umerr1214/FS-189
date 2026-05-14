#include <iostream>
#include <vector>
#include <numeric> // For std::iota

// Semantic error: The loop goes one element too far, causing an out-of-bounds write.
// This leads to undefined behavior.
void initializeWithDefaults(int* arr, int size) {
    for (int i = 0; i <= size; ++i) { // Should be i < size
        arr[i] = -1; // Accesses arr[size], which is out of bounds
    }
}

int main() {
    // Test Case 1: Standard array
    int arr1[5];
    std::iota(arr1, arr1 + 5, 1); // arr1: {1, 2, 3, 4, 5}
    
    // A sentinel value immediately after arr1 to try and observe potential corruption.
    // This is for demonstration; actual undefined behavior is not guaranteed to manifest this way.
    int sentinel_after_arr1 = 999; 

    initializeWithDefaults(arr1, 5); // Will write to arr1[5] (out of bounds)
    std::cout << "arr1: [";
    for (int i = 0; i < 5; ++i) {
        std::cout << arr1[i] << (i < 4 ? ", " : "");
    }
    std::cout << "]" << std::endl; 
    std::cout << "Sentinel after arr1 (may be corrupted): " << sentinel_after_arr1 << std::endl;

    // Test Case 2: std::vector
    std::vector<int> vec2(3);
    std::iota(vec2.begin(), vec2.end(), 10); // vec2: {10, 20, 30}
    initializeWithDefaults(vec2.data(), vec2.size()); // Will write to vec2.data()[3] (out of bounds)
    std::cout << "vec2: [";
    for (int i = 0; i < 3; ++i) {
        std::cout << vec2[i] << (i < 2 ? ", " : "");
    }
    std::cout << "]" << std::endl;

    // Test Case 3: Empty array (size 0)
    int arr3[0]; 
    initializeWithDefaults(arr3, 0); // Loop `i <= 0` runs for i=0, accesses arr3[0] (out of bounds for size 0)
    std::cout << "arr3: []" << std::endl; // No elements to print, but undefined behavior occurred.

    return 0;
}