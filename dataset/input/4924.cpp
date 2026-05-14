#include <iostream>

int main() {
    int number;
    std::cout << "Enter an integer: ";
    std::cin >> number // Missing semicolon here

    if (number > 0) {
        std::cout << "The number is positive." << std::endl;
    } else if (number < 0) {
        std::cout << "The number is negative." << std::endl;
    } else {
        std::cout << "The number is zero." << std::endl;
    }

    return 0;
}