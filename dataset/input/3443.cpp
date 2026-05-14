#include <iostream>

int main() {
    int arr[5];
    std::cout << "Enter 5 integer values:" << std::endl;

    for (int i = 0; i < 5; ++i) {
        std::cin >> arr[i];
    }

    // Logical Error: Initializing 'largest' to 0.
    // If all input numbers are negative, this will incorrectly report 0 as the largest.
    int largest = 0; 
    for (int i = 0; i < 5; ++i) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    std::cout << "The largest element is: " << largest << std::endl;
    return 0;
}