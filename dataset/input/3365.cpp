#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void rotateLeft(std::vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 0 || k == 0) return;
    k %= n;

    std::vector<int> temp;
    for (int i = 0; i < k; ++i) {
        temp.push_back(arr[i]);
    }

    // Logical error: The loop for shifting elements stops one element too early.
    // It should iterate up to 'n', but stops at 'n - 1'.
    for (int i = k; i < n - 1; ++i) { // Should be 'i < n'
        arr[i - k] = arr[i];
    }

    for (int i = 0; i < k; ++i) {
        arr[n - k + i] = temp[i];
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int k;
    std::cin >> k;

    rotateLeft(arr, k);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;
    return 0;
}