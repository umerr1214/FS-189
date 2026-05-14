#include <iostream>

int main() {
    int num1, num2, num3;

    std::cout << "Enter three distinct integer numbers:" << std::endl;

    std::cout << "Number 1: ";
    std::cin >> num1;
    if (std::cin.fail()) {
        std::cout << "Error: Invalid input for Number 1. Please enter an integer." << std::endl;
        return 1;
    }

    std::cout << "Number 2: ";
    std::cin >> num2;
    if (std::cin.fail()) {
        std::cout << "Error: Invalid input for Number 2. Please enter an integer." << std::endl;
        return 1;
    }

    std::cout << "Number 3: ";
    std::cin >> num3;
    if (std::cin.fail()) {
        std::cout << "Error: Invalid input for Number 3. Please enter an integer." << std::endl;
        return 1;
    }

    // Check for distinctness using if-else statements as required by the prompt
    if (num1 == num2 || num1 == num3 || num2 == num3) {
        std::cout << "Error: Numbers must be distinct." << std::endl;
        return 1;
    }

    // Sorting logic using conditional swaps (readable and efficient for 3 elements)
    // This is a correct and common approach for sorting a small fixed number of elements
    // using only if-else statements without arrays or dedicated algorithms.
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    if (num2 > num3) {
        int temp = num2;
        num2 = num3;
        num3 = temp;
    }
    if (num1 > num2) { // One more check for num1 and num2 after num2 might have moved
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    std::cout << "Sorted numbers: " << num1 << " " << num2 << " " << num3 << std::endl;

    return 0;
}