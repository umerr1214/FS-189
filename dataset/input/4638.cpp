#include <iostream>
#include <vector>
#include <limits>

// Function to find the largest element in an array
// Returns std::numeric_limits<int>::min() if array is empty.
int findLargest(const std::vector<int>& arr) {
    if (arr.empty()) {
        return std::numeric_limits<int>::min(); // Sentinel value
    }

    int largest = arr[0];
    // SEMANTIC ERROR: The loop condition 'i <= arr.size()' causes an out-of-bounds access
    // when 'i' becomes equal to 'arr.size()'. Valid indices are 0 to arr.size() - 1.
    // Accessing arr[arr.size()] leads to undefined behavior.
    for (size_t i = 0; i <= arr.size(); ++i) { // Should be 'i < arr.size()'
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