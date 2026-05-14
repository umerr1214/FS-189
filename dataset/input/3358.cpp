#include <iostream>
#include <vector>

int countOccurrences(const std::vector<int>& arr, int target) {
    int count = 0;
    for (int x : arr) {
        if (x == target) {
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
    int target // Missing semicolon here
    std::cin >> target;

    std::cout << countOccurrences(arr, target) << std::endl;

    return 0;
}