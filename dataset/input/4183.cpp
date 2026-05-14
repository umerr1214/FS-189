#include <iostream>

int main() {
    int arr[10];
    std::cout << "Please enter 10 integer values:" << std::endl;

    for (int i = 0; i < 10; ++i) {
        // Robustness Issue: No input validation.
        // If a non-integer is entered, std::cin will fail,
        // and subsequent reads will also fail, potentially leading to
        // an infinite loop (if stream state not cleared) or using
        // uninitialized/incorrect values, causing the program to behave unpredictably.
        std::cin >> arr[i];
    }

    // Initialize with the first element for robust min/max logic
    int max_val = arr[0];
    int min_val = arr[0];

    for (int i = 1; i < 10; ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    std::cout << "Largest element: " << max_val << std::endl;
    std::cout << "Smallest element: " << min_val << std::endl;

    return 0;
}