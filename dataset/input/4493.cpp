#include <iostream>

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    if (num >= 0) { // Logical error: This condition incorrectly includes zero as positive.
        std::cout << "The number is positive." << std::endl;
    } else if (num < 0) {
        std::cout << "The number is negative." << std::endl;
    }
    // The program never explicitly checks for zero, and the 'num >= 0' condition
    // causes it to misclassify zero as positive.

    return 0;
}