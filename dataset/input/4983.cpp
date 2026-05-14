#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort

// This program correctly and efficiently finds the second largest element
// in a one-dimensional array of 5 integers. It handles duplicates and
// cases where all elements might be the same.
int user_main() {
    std::vector<int> arr(5);
    for (int i = 0; i < 5; ++i) {
        std::cin >> arr[i];
    }

    // Efficiently sort the array in ascending order.
    // std::sort typically uses an IntroSort algorithm, providing O(N log N) average complexity.
    std::sort(arr.begin(), arr.end());

    // The largest element is now at the last position (index 4).
    // Initialize second_largest with the largest element. This handles the
    // edge case where all elements in the array are identical (e.g., 10 10 10 10 10),
    // in which case the largest value itself is considered the "second largest".
    int largest = arr[4];
    int second_largest = largest;

    // Iterate backwards from the second-to-last element (index 3)
    // to find the first element that is strictly less than the largest.
    // This ensures we find the second *distinct* largest element.
    for (int i = 3; i >= 0; --i) {
        if (arr[i] < largest) {
            second_largest = arr[i];
            break; // Found the second distinct largest element, no need to continue
        }
        // If arr[i] == largest, continue searching further down the array
        // to find a distinct smaller value.
    }

    std::cout << second_largest << std::endl;

    return 0;
}

// Wrapper main for standalone compilation and execution
int main() {
    return user_main();
}