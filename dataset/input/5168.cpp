#include <iostream>
#include <limits> // Required for robust input handling in main

// Function to perform linear search with readability issues
int linearSearch(const int arr[], int size, int target) {
    int idx = 0;         // Uses a less descriptive variable name for index
    bool found_it = false; // Unnecessary boolean flag to track if target is found
    int result_idx = -1; // Variable to store the found index, initialized to -1

    // Uses a while loop with manual index increment, which is less idiomatic
    // and potentially less clear than a standard for loop for this task.
    while (idx < size) {
        if (arr[idx] == target) {
            found_it = true;    // Set flag
            result_idx = idx;   // Store the index
            break;              // Exit loop once target is found
        }
        idx++; // Manual increment of the index
    }

    // Returns based on the boolean flag after the loop, adding an extra conditional check
    // instead of returning directly from inside the loop.
    if (found_it) {
        return result_idx;
    } else {
        return -1;
    }
}

int main() {
    const int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    std::cout << "Array: {";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i == size - 1 ? "" : ", ");
    }
    std::cout << "}" << std::endl;

    std::cout << "Enter the target element to search: ";
    // Robust input handling for main, ensuring a valid integer is read
    while (!(std::cin >> target)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear(); // Clear the error flags
        // Discard invalid input from the buffer up to the newline character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        std::cout << "Target " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Target " << target << " not found in the array." << std::endl;
    }

    return 0;
}