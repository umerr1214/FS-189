#include <iostream>
#include <vector>
// No <algorithm> for std::sort to demonstrate efficiency issue

// This program finds the second largest element, but uses an inefficient
// sorting algorithm (Bubble Sort) and a slightly verbose approach
// to find the second largest, impacting readability and efficiency.
int user_main() {
    std::vector<int> arr(5);
    for (int i = 0; i < 5; ++i) {
        std::cin >> arr[i];
    }

    // Efficiency issue: Using Bubble Sort (O(N^2)) instead of a more efficient
    // algorithm like std::sort (typically O(N log N)). For N=5, the performance
    // difference is negligible, but it's a poor practice for larger arrays.
    for (int i = 0; i < 5 - 1; ++i) {
        for (int j = 0; j < 5 - i - 1; ++j) {
            if (arr[j] > arr[j+1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Readability issue: After sorting, the second largest distinct element
    // could be found more concisely. This approach is correct but slightly
    // more verbose than necessary for a small, sorted array.
    int largest = arr[4]; // The largest element is at the end after sorting
    int second_largest = largest; // Initialize with largest, handles case where all elements are same

    // Iterate backwards from the second-to-last element to find the first
    // element that is strictly smaller than the largest.
    for (int i = 3; i >= 0; --i) {
        if (arr[i] < largest) {
            second_largest = arr[i];
            break; // Found the second distinct largest element
        }
        // If arr[i] == largest, continue searching downwards to find a distinct value
    }

    std::cout << second_largest << std::endl;

    return 0;
}

// Wrapper main for standalone compilation and execution
int main() {
    return user_main();
}