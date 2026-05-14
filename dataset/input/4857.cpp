#include <iostream>

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    int targetNumber;
    bool isFound = false;
    int foundIndex = -1;

    std::cout << "Enter a number to search for: ";
    std::cin >> targetNumber;

    // Perform a linear search for the target number
    for (int i = 0; i < 5; ++i) {
        if (numbers[i] == targetNumber) {
            isFound = true;
            foundIndex = i;
            break; // Efficient: Exit loop as soon as the number is found
        }
    }

    // Print the result based on whether the number was found
    if (isFound) {
        std::cout << "Number found at index: " << foundIndex << std::endl;
    } else {
        std::cout << "not found" << std::endl;
    }

    return 0;
}