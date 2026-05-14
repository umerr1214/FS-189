#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm> // For std::rotate

// Helper function to print the vector
void printVector(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

// Function to perform left rotation - Correct Version
void leftRotate(std::vector<int>& arr, int k) {
    if (arr.empty() || k == 0) {
        return;
    }

    // Correct Version: Uses std::rotate for an efficient and idiomatic C++ solution.
    // std::rotate partitions the range [first, last) into [first, middle) and [middle, last),
    // and rotates them such that the elements in [middle, last) come before the elements in [first, middle).
    // For a left rotation by k positions, 'middle' should be arr.begin() + k.
    // The complexity of std::rotate is linear (O(N)), making it efficient.
    // It is also highly readable and leverages the C++ Standard Library.

    // Normalize k to be within the range [0, arr.size()-1]
    // This handles cases where k is greater than or equal to arr.size()
    // by effectively rotating by k % arr.size() positions.
    k = k % arr.size();

    // Perform the rotation using std::rotate
    // arr.begin() is the 'first' iterator.
    // arr.begin() + k is the 'middle' iterator (the element that becomes the new first).
    // arr.end() is the 'last' iterator.
    std::rotate(arr.begin(), arr.begin() + k, arr.end());
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num_test_cases;
    std::cin >> num_test_cases;
    while (num_test_cases--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
        leftRotate(arr, k);
        printVector(arr);
    }
    return 0;
}