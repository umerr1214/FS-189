#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    if (n == 0) {
        std::cout << "Array is empty or no elements provided." << std::endl;
        return 0;
    }

    // Readability / Efficiency Issue: Sorting the entire array (O(N log N))
    // is inefficient when only the maximum element (O(N)) is needed.
    std::sort(arr.begin(), arr.end());

    // After sorting, the largest element is at the end of the array
    std::cout << arr.back() << std::endl;

    return 0;
}