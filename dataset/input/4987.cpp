#include <iostream>
#include <vector>
#include <algorithm> // Not used in the problematic function, but common

// Function with a robustness issue: crashes for size = 0
// due to out-of-bounds access.
void reverseArray(int* arr, int size) {
    // This loop condition is problematic for size = 0.
    // For size = 0: (0 - 1) / 2 = -1 / 2 = 0 (integer division truncates towards zero).
    // The loop runs for i = 0.
    // Inside the loop: arr[i] becomes arr[0] and arr[size - 1 - i] becomes arr[0 - 1 - 0] = arr[-1].
    // Accessing arr[-1] is undefined behavior and will likely lead to a segmentation fault or crash.
    for (int i = 0; i <= (size - 1) / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

// Helper function to print the contents of a vector
void printArray(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Testing reverseArray with Robustness Issue:" << std::endl;

    // Test Case 1: Standard odd number of elements
    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::cout << "Original: ";
    printArray(arr1);
    reverseArray(arr1.data(), arr1.size());
    std::cout << "Reversed: ";
    printArray(arr1);
    std::cout << std::endl;

    // Test Case 2: Even number of elements
    std::vector<int> arr2 = {10, 20, 30, 40};
    std::cout << "Original: ";
    printArray(arr2);
    reverseArray(arr2.data(), arr2.size());
    std::cout << "Reversed: ";
    printArray(arr2);
    std::cout << std::endl;

    // Test Case 3: Single element array (works correctly)
    std::vector<int> arr3 = {100};
    std::cout << "Original: ";
    printArray(arr3);
    reverseArray(arr3.data(), arr3.size());
    std::cout << "Reversed: ";
    printArray(arr3);
    std::cout << std::endl;

    // Test Case 4: Empty array - EXPECTED CRASH
    // This test case is designed to trigger the robustness issue.
    // The program is expected to terminate abnormally here due to out-of-bounds access.
    std::vector<int> arr4;
    std::cout << "Original (empty): ";
    printArray(arr4);
    std::cout << "Attempting to reverse empty array (expected crash/undefined behavior)..." << std::endl;
    // The call below will likely cause a segmentation fault or similar crash.
    reverseArray(arr4.data(), arr4.size());
    std::cout << "Reversed (empty): "; // This line might not be reached if crash occurs
    printArray(arr4);
    std::cout << std::endl;

    return 0;
}