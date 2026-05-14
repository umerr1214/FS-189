#include <iostream>
#include <vector>
#include <algorithm> // Not strictly needed for this specific logic, but often useful.
#include <limits>    // For std::numeric_limits<int>::min()

// Function to find the second largest element in a 1D array of integers.
// This is a correct, efficient, and robust implementation.
// It uses a single pass (O(N) time complexity) and handles edge cases
// (empty array, single-element array, all elements identical) by returning
// std::numeric_limits<int>::min() to indicate that a distinct second largest
// element was not found.
int findSecondLargest(const std::vector<int>& arr) {
    if (arr.size() < 2) {
        // If the array has fewer than two elements, a distinct second largest
        // element cannot exist. Return a sentinel value.
        return std::numeric_limits<int>::min();
    }

    int max1 = std::numeric_limits<int>::min(); // Stores the largest element found so far
    int max2 = std::numeric_limits<int>::min(); // Stores the second largest element found so far

    // Iterate through the array once to find max1 and max2.
    for (int x : arr) {
        if (x > max1) {
            // If current element 'x' is greater than the current largest (max1),
            // then current max1 becomes the new second largest (max2),
            // and 'x' becomes the new largest (max1).
            max2 = max1;
            max1 = x;
        } else if (x > max2 && x != max1) {
            // If 'x' is not greater than max1, but is greater than max2,
            // and is distinct from max1 (to handle duplicate largest elements),
            // then 'x' becomes the new second largest (max2).
            max2 = x;
        }
    }
    
    // After the loop, max2 holds the second largest distinct element.
    // If max2 is still INT_MIN, it means either:
    // a) The array had only one distinct element (e.g., {5}), handled by the initial size check.
    // b) All elements were identical (e.g., {5, 5, 5}), and no distinct second largest exists.
    // In both cases, returning INT_MIN correctly signifies "no distinct second largest found".
    return max2;
}

int main() {
    // Example usage with various test cases
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
    
    std::vector<int> arr7 = {-5, -1, -10};
    std::cout << "Second largest in {-5, -1, -10}: " << findSecondLargest(arr7) << std::endl; // Expected: -5

    std::vector<int> arr8 = {10, 10, 5};
    std::cout << "Second largest in {10, 10, 5}: " << findSecondLargest(arr8) << std::endl; // Expected: 5

    std::vector<int> arr9 = {5, 10, 10};
    std::cout << "Second largest in {5, 10, 10}: " << findSecondLargest(arr9) << std::endl; // Expected: 5

    return 0;
}