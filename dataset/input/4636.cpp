#include <iostream>
#include <vector>
#include <limits> // Required for std::numeric_limits

// Function to find the largest element in an array
// Returns std::numeric_limits<int>::min() if array is empty,
// though the main function handles printing "Array is empty."
int findLargest(const std::vector<int>& arr) {
    if (arr.empty()) {
        return std::numeric_limits<int>::min();
    }

    int largest = arr[0] // SYNTAX ERROR: Missing semicolon
    for (size_t i = 1; i < arr.size(); ++i) {
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