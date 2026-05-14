#include <iostream>
#include <limits> // Required for numeric_limits

int main() {
    const int SIZE = 5;
    int arr[SIZE];

    std::cout << "Enter " << SIZE << " integer values for the array:\n";

    for (int i = 0; i < SIZE; ++i) {
        std::cout << "Enter value " << i + 1 << ": ";
        std::cin >> arr[i];

        // Robustness Issue: Does not handle non-integer input.
        // If user enters non-integer, `cin` will enter a fail state,
        // `arr[i]` will not be updated, and the loop will likely
        // become infinite as `cin >> arr[i]` will continuously fail
        // without clearing the error or ignoring the bad input.
    }

    // Initialize min/max with the first element
    int max_val = arr[0];
    int min_val = arr[0];

    // Iterate to find largest and smallest
    for (int i = 1; i < SIZE; ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    std::cout << "Largest: " << max_val << "\n";
    std::cout << "Smallest: " << min_val << "\n";

    return 0;
}