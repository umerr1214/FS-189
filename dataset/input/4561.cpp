#include <iostream>
#include <vector>
#include <algorithm> // Not strictly needed, but good for general array operations
#include <limits>    // For std::numeric_limits

// Function to find the second largest element in an array.
// This version has a robustness issue: it returns std::numeric_limits<int>::min()
// for cases where a distinct second largest element does not exist (e.g., array
// has fewer than 2 elements, or all elements are identical). While this value
// might be technically correct in some contexts (as "not found"), it lacks
// explicit error handling or a more informative return type (like std::optional<int>
// or a boolean flag), making the interpretation ambiguous if INT_MIN itself
// could be a valid element in the input array.
int findSecondLargest(const std::vector<int>& arr) {
    if (arr.empty()) {
        return std::numeric_limits<int>::min(); // No elements, no second largest
    }

    int max1 = std::numeric_limits<int>::min(); // Stores the largest element
    int max2 = std::numeric_limits<int>::min(); // Stores the second largest element

    for (int x : arr) {
        if (x > max1) {
            max2 = max1; // Current max1 becomes second largest
            max1 = x;    // Current element becomes new largest
        } else if (x > max2 && x != max1) {
            // Current element is not the largest, but is greater than the second largest
            // and is distinct from the largest.
            max2 = x;
        }
    }
    
    // The robustness issue here is that for cases like {100} or {7,7,7,7},
    // max2 will remain INT_MIN. The program doesn't differentiate between
    // "no second largest" and "INT_MIN is the second largest element".
    // It works correctly for typical cases, but edge case handling lacks clarity.
    return max2;
}

int main() {
    // Example usage
    std::vector<int> arr1 = {10, 5, 20, 15, 25};
    std::cout << "Second largest in {10, 5, 20, 15, 25}: " << findSecondLargest(arr1) << std::endl; // Expected: 20

    std::vector<int> arr2 = {7, 7, 7, 7};
    // Robustness issue here: returns INT_MIN, but doesn't explicitly state "no distinct second largest"
    std::cout << "Second largest in {7, 7, 7, 7}: " << findSecondLargest(arr2) << std::endl; // Expected: INT_MIN

    std::vector<int> arr3 = {100};
    // Robustness issue here: returns INT_MIN, but doesn't explicitly state "array too small"
    std::cout << "Second largest in {100}: " << findSecondLargest(arr3) << std::endl; // Expected: INT_MIN

    std::vector<int> arr4 = {};
    // Robustness issue here: returns INT_MIN, but doesn't explicitly state "empty array"
    std::cout << "Second largest in {}: " << findSecondLargest(arr4) << std::endl; // Expected: INT_MIN

    std::vector<int> arr5 = {1, 2};
    std::cout << "Second largest in {1, 2}: " << findSecondLargest(arr5) << std::endl; // Expected: 1

    std::vector<int> arr6 = {2, 1};
    std::cout << "Second largest in {2, 1}: " << findSecondLargest(arr6) << std::endl; // Expected: 1
    
    std::vector<int> arr7 = {10, 10, 5};
    std::cout << "Second largest in {10, 10, 5}: " << findSecondLargest(arr7) << std::endl; // Expected: 5

    return 0;
}