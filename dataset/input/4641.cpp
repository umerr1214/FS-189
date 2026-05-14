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

    if (n == 0) {
        std::cout << "Array is empty or no elements provided." << std::endl;
        return 0;
    }

    int largest_element = arr[0]; // Initialize with the first element
    for (int i = 1; i < n; ++i) {
        if (arr[i] > largest_element) {
            largest_element = arr[i];
        }
    }

    std::cout << largest_element << std::endl;

    return 0;
}