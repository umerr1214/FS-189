#include <iostream>

int main() {
    int arr[10];
    int max_val;

    std::cout << "Enter 10 integer values:" << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << "Enter value " << i + 1 << ": " // Missing semicolon here
        std::cin >> arr[i];
    }

    // Assume array is not empty and has at least one element
    max_val = arr[0];

    for (int i = 1; i < 10; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    std::cout << "The largest element in the array is: " << max_val << std::endl;

    return 0;
}