#include <iostream>

int main() {
    int arr[10];
    std::cout << "Enter 10 integers:" << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cin >> arr[i];
    }

    // Semantic Error: Variables 'largest' and 'smallest' are declared but not initialized.
    // Their initial values are indeterminate (garbage), leading to undefined behavior
    // when compared with array elements in the first iteration.
    int largest;
    int smallest; 

    for (int i = 0; i < 10; ++i) {
        if (arr[i] > largest) { // Comparison with an indeterminate value
            largest = arr[i];
        }
        if (arr[i] < smallest) { // Comparison with an indeterminate value
            smallest = arr[i];
        }
    }

    std::cout << "Largest element: " << largest << std::endl;
    std::cout << "Smallest element: " << smallest << std::endl;

    return 0;
}