#include <iostream>

// Function to perform linear search
int linearSearch(const int arr[], int size, int target) {
    // Iterate through the array elements
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // Target found, return its index immediately
        }
    }
    return -1; // Target not found after checking all elements
}

int main() {
    const int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 0; // Robustness issue: Initialize target to a default value (0).
                    // If std::cin fails, this default value will be used without user notification.

    std::cout << "Array: {";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i == size - 1 ? "" : ", ");
    }
    std::cout << "}" << std::endl;

    std::cout << "Enter the target element to search: ";
    std::cin >> target; // Robustness issue: No input validation.
                        // If non-integer input is provided, std::cin enters a fail state,
                        // and 'target' retains its default value (0).
                        // The program proceeds to search for 0 without informing the user
                        // about the invalid input.

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        std::cout << "Target " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Target " << target << " not found in the array." << std::endl;
    }

    return 0;
}