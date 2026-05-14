#include <iostream>
#include <vector>
#include <numeric> // For std::iota if needed

// Helper function to print the vector
void printVector(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

// Function to perform left rotation with an efficiency issue
void leftRotate(std::vector<int>& arr, int k) {
    if (arr.empty() || k == 0) {
        return;
    }

    // Efficiency Issue: This approach performs 'k' individual left shifts.
    // Each shift takes O(n) time (where n is arr.size()) because every element
    // needs to be moved. So, the total time complexity is O(k * n).
    // For large 'k' and 'n', this is very inefficient compared to optimal O(n) algorithms
    // (like using a temporary array or the reversal algorithm).
    // The 'k' value is normalized (k = k % n) to ensure correctness for k >= n,
    // but the fundamental inefficiency of repeated single shifts remains.

    int n = arr.size();
    k = k % n; // Normalize k to avoid unnecessary full rotations

    for (int rotation_count = 0; rotation_count < k; ++rotation_count) {
        int first_element = arr[0];
        for (int i = 0; i < n - 1; ++i) {
            arr[i] = arr[i+1];
        }
        arr[n-1] = first_element;
    }
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