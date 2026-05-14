#include <iostream>

int main() {
    int arr[5];
    int size = 5;

    std::cout << "Enter 5 integer values:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter value for element " << i << ": ";
        std::cin >> arr[i] // Missing semicolon here, will cause a syntax error
    }

    int maxVal = arr[0];
    int minVal = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }

    std::cout << "Largest element: " << maxVal << std::endl;
    std::cout << "Smallest element: " << minVal << std::endl;

    return 0;
}