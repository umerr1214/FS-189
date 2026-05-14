#include <iostream>

int main() {
    int arr[10]; // 1D integer array with 10 elements

    // Initialize array with values from 1 to 10
    for (int i = 0; i < 10; ++i) {
        arr[i] = i + 1;
    }

    long long evenSum = 0;
    // LOGICAL ERROR: Product should be initialized to 1, not 0.
    // Initializing to 0 will make the final product always 0 if any odd number is present.
    long long oddProduct = 0; 

    for (int i = 0; i < 10; ++i) {
        if (arr[i] % 2 == 0) {
            evenSum += arr[i];
        } else {
            oddProduct *= arr[i];
        }
    }

    std::cout << "Array elements: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << (i == 9 ? "" : ", ");
    }
    std::cout << std::endl;

    std::cout << "Sum of even numbers: " << evenSum << std::endl;
    std::cout << "Product of odd numbers: " << oddProduct << std::endl;

    return 0;
}