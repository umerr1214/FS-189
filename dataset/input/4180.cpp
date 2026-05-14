#include <iostream>
#include <limits> // Required for std::numeric_limits

int main() {
    int arr[10] // Syntax Error: Missing semicolon here
    std::cout << "Enter 10 integers:" << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cin >> arr[i];
    }

    int largest = std::numeric_limits<int>::min();
    int smallest = std::numeric_limits<int>::max();

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