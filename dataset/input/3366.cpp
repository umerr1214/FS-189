#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Semantic error: 'arr' is passed by value, meaning a copy of the vector is made.
// Modifications to 'arr' inside this function will not affect the original vector
// passed from the 'main' function.
void rotateLeft(std::vector<int> arr, int k) { // Should be 'std::vector<int>& arr'
    int n = arr.size();
    if (n == 0 || k == 0) return;
    k %= n;

    std::vector<int> temp;
    for (int i = 0; i < k; ++i) {
        temp.push_back(arr[i]);
    }

    for (int i = k; i < n; ++i) {
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

    rotateLeft(arr, k); // Calls the function, but the 'arr' in main remains unchanged.

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;
    return 0;
}