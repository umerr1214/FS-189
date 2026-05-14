#include <iostream>
#include <vector>
#include <limits> // Still good to include, even if not directly used for the error

// Function to find the largest element in an array
// Returns std::numeric_limits<int>::min() if array is empty.
int findLargest(const std::vector<int>& arr) {
    if (arr.empty()) {
        return std::numeric_limits<int>::min(); // Sentinel value
    }

    int largest = 0; // LOGICAL ERROR: This initialization fails if all array elements are negative.
                     // For example, for {-10, -5, -20}, it will incorrectly return 0 instead of -5.

    // The loop starts from 0 to compare all elements against the initial 'largest' value.
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

int main() {
    int n;
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Array is empty." << std::endl;
        return 0;
    }

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int result = findLargest(arr);
    std::cout << result << std::endl;

    return 0;
}