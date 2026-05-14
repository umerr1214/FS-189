#include <iostream>
#include <vector>
#include <limits> // Required for std::numeric_limits

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Robustness Issue: Does not handle an empty array (n=0)
    // If n is 0, accessing arr[0] will result in undefined behavior,
    // likely a segmentation fault or crash.
    int largest_element = arr[0]; 

    for (int i = 1; i < n; ++i) {
        if (arr[i] > largest_element) {
            largest_element = arr[i];
        }
    }

    std::cout << largest_element << std::endl;

    return 0;
}