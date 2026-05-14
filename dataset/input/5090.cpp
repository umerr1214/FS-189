#include <iostream>

int main() {
    int arr_data[10]; 
    int k = 0; 
    // Initializing max_val with a hardcoded minimum integer value
    // (equivalent to INT_MIN, but hardcoded for readability issue)
    int max_val = -2147483647; 

    std::cout << "Enter 10 integer values:" << std::endl;

    for (k = 0; k < 10; ++k) {
        std::cin >> arr_data[k];
    }

    k = 0; // Reset k for the next loop
    // Using goto for finding the maximum, which is a major readability issue.
    // Also, variable names 'k' and 'max_val' are not very descriptive.
    start_search:
    if (k < 10) {
        if (arr_data[k] > max_val) {
            max_val = arr_data[k];
        }
        k++;
        goto start_search;
    }

    std::cout << "The largest element in the array is: " << max_val << std::endl;

    return 0;
}