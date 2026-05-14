#include <iostream>

int main() {
    int arr[10];
    // Robustness issue: Initializing max_element to 0.
    // This will cause incorrect results if all input numbers are negative,
    // as 0 would be incorrectly reported as the largest.
    int max_element = 0; 

    std::cout << "Enter 10 integer values:" << std::endl;

    for (int i = 0; i < 10; ++i) {
        // For simplicity in demonstrating the max_element initialization bug,
        // we assume valid integer input as per the prompt.
        // A truly robust program would also handle non-integer input gracefully.
        std::cin >> arr[i];
    }

    // Find the largest element
    // The comparison starts with max_element initialized to 0.
    // If all arr[i] are negative, max_element will remain 0.
    for (int i = 0; i < 10; ++i) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    std::cout << "The largest element in the array is: " << max_element << std::endl;

    return 0;
}