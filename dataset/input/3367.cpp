#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm> // For std::reverse

// Helper function to print the vector
void printVector(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

// Function to perform left rotation with a robustness issue
void leftRotate(std::vector<int>& arr, int k) {
    if (arr.empty()) {
        return;
    }

    // Robustness Issue: The 'k' value is not normalized (k = k % arr.size()).
    // If k is greater than arr.size(), accessing arr.begin() + k will result in
    // an iterator out of bounds, leading to undefined behavior or a crash.
    // For example, if arr.size() is 3 and k is 4, arr.begin() + 4 is an invalid iterator,
    // causing a runtime error in std::reverse.
    // This makes the function fragile to inputs where k > arr.size().

    // k is assumed to be non-negative based on problem context.
    size_t actual_k = static_cast<size_t>(k);

    // The reversal algorithm implementation
    // This line can cause a crash if actual_k > arr.size()
    std::reverse(arr.begin(), arr.begin() + actual_k);
    // This line can cause a crash if actual_k > arr.size()
    std::reverse(arr.begin() + actual_k, arr.end());
    std::reverse(arr.begin(), arr.end());
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