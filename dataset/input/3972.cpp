#include <iostream>

int main() {
    int arr[10]; // 1D integer array with 10 elements (indices 0-9)

    // SEMANTIC ERROR: Loop condition i <= 10 attempts to write to arr[10], which is out of bounds.
    // This is undefined behavior, but for demonstration, we assume it writes '11' to arr[10].
    for (int i = 0; i <= 10; ++i) { 
        arr[i] = i + 1;
    }

    long long evenSum = 0;
    long long oddProduct = 1;

    // SEMANTIC ERROR: Loop condition i <= 10 attempts to read from arr[10], which is out of bounds.
    // This reads the value written by the previous loop (assumed to be 11).
    for (int i = 0; i <= 10; ++i) {
        if (arr[i] % 2 == 0) {
            evenSum += arr[i];
        } else {
            oddProduct *= arr[i];
        }
    }

    std::cout << "Array elements: ";
    // This loop correctly prints the first 10 elements (indices 0-9).
    for (int i = 0; i < 10; ++i) { 
        std::cout << arr[i] << (i == 9 ? "" : ", ");
    }
    std::cout << std::endl;

    std::cout << "Sum of even numbers: " << evenSum << std::endl;
    std::cout << "Product of odd numbers: " << oddProduct << std::endl;

    return 0;
}