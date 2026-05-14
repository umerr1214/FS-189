#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort
#include <limits>    // For std::numeric_limits

// Function to find the second largest element in an array.
// This version has an efficiency issue: it sorts the entire array,
// which takes O(N log N) time, even though finding the two largest
// elements can be done in a single pass (O(N) time).
int findSecondLargest(std::vector<int> arr) { // Pass by value to allow modification/sorting
    if (arr.size() < 2) {
        // No second largest for arrays with less than two elements.
        return std::numeric_limits<int>::min();
    }

    // Efficiency Issue: Sorting the entire array is O(N log N).
    // A more efficient approach would be a single pass (O(N)).
    std::sort(arr.begin(), arr.end());

    // After sorting, iterate from the end to find the second distinct largest element.
    // This part is correct, but the initial sort is inefficient.
    int largest = arr.back();
    for (int i = arr.size() - 2; i >= 0; --i) {
        if (arr[i] != largest) {
            return arr[i];
        }
    }

    // If we reach here, all elements are the same (e.g., {7, 7, 7}).
    // In this case, there is no distinct second largest element.
    return std::numeric_limits<int>::min();
}

int main() {
    // Example usage
    std::vector<int> arr1 = {10, 5, 20, 15, 25};
    std::cout << "Second largest in {10, 5, 20, 15, 25}: " << findSecondLargest(arr1) << std::endl; // Expected: 20

    std::vector<int> arr2 = {7, 7, 7, 7};
    std::cout << "Second largest in {7, 7, 7, 7}: " << findSecondLargest(arr2) << std::endl; // Expected: INT_MIN

    std::vector<int> arr3 = {100};
    std::cout << "Second largest in {100}: " << findSecondLargest(arr3) << std::endl; // Expected: INT_MIN

    std::vector<int> arr4 = {};
    std::cout << "Second largest in {}: " << findSecondLargest(arr4) << std::endl; // Expected: INT_MIN

    std::vector<int> arr5 = {1, 2};
    std::cout << "Second largest in {1, 2}: " << findSecondLargest(arr5) << std::endl; // Expected: 1

    std::vector<int> arr6 = {2, 1};
    std::cout << "Second largest in {2, 1}: " << findSecondLargest(arr6) << std::endl; // Expected: 1
    
    std::vector<int> arr7 = {10, 10, 5};
    std::cout << "Second largest in {10, 10, 5}: " << findSecondLargest(arr7) << std::endl; // Expected: 5

    return 0;
}