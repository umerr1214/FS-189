#include <iostream>

int main() {
    int arr[5];
    std::cout << "Enter 5 integer values:" << std::endl;

    for (int i = 0; i < 5; ++i) {
        std::cin >> arr[i];
    }

    int largest = arr[0];
    for (int i = 1; i < 5; ++i) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    std::cout << "The largest element is: " << largest std::endl; // Syntax Error: Missing semicolon after 'largest'
    return 0;
}