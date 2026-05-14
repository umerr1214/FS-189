#include <iostream>
#include <vector>
#include <string> // Not strictly needed, but common

// Function containing the main logic for testing
int solve_and_print() {
    int arr[8] = {10, 20, 5, 30, 40, 50, 60, 70};
    int target = -1; // Default value, will be used if cin fails
    int found_index = -1;

    std::cout << "Enter the integer to search: ";
    std::cin >> target; // Robustness issue: no check for cin failure

    // If cin fails (e.g., non-integer input), 'target' remains -1.
    // The program will proceed to search for -1.
    // This is a robustness issue as it doesn't handle invalid input gracefully
    // and proceeds with a potentially unintended default value.

    for (int i = 0; i < 8; ++i) {
        if (arr[i] == target) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1) {
        std::cout << "Found at index " << found_index << std::endl;
    } else {
        std::cout << "Not present" << std::endl;
    }

    return 0;
}

int main() {
    return solve_and_print();
}