#include <iostream>

int main() {
    int arr[10];
    std::cout << "Enter 10 integers:" << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cin >> arr[i];
    }

    // Logical Error: Initializing 'largest' and 'smallest' to 0.
    // This will cause incorrect results if all input numbers are negative
    // (largest will incorrectly be 0) or if all input numbers are positive
    // (smallest will incorrectly be 0).
    int largest = 0;
    int smallest = 0; 

    for (int i = 0; i < 10; ++i) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    std::cout << "Largest element: " << largest << std::endl;
    std::cout << "Smallest element: " << smallest << std::endl;

    return 0;
}