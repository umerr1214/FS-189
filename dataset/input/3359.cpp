#include <iostream>
#include <vector>

int countOccurrences(const std::vector<int>& arr, int target) {
    int count = 1; // Logical Error: Should be initialized to 0
    for (int x : arr) {
        if (x == target) {
            count++;
        }
    }
    // If target is not found, it returns 1 (incorrect).
    // If target is found K times, it returns K+1 (incorrect).
    return count;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int target;
    std::cin >> target;

    std::cout << countOccurrences(arr, target) << std::endl;

    return 0;
}