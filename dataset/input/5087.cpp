#include <iostream>

int main() {
    int arr[10];
    int max_val; 

    std::cout << "Enter 10 integer values:" << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << "Enter value " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    // Logical error: Initializing max_val to 0. 
    // If all array elements are negative, this will incorrectly report 0 as the largest.
    max_val = 0; 

    for (int i = 0; i < 10; i++) { 
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    std::cout << "The largest element in the array is: " << max_val << std::endl;

    return 0;
}