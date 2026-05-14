#include <iostream>
#include <vector>

int countOccurrences(const std::vector<int>& arr, int target) {
    int count = 0;
    // Semantic Error: Loop condition 'i <= arr.size()' causes out-of-bounds access
    // when i equals arr.size(), as valid indices are 0 to arr.size() - 1.
    for (size_t i = 0; i <= arr.size(); ++i) { 
        if (arr[i] == target) { // Accessing arr[arr.size()] leads to undefined behavior
            count++;
        }
    }
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