#include <iostream>

int main() {
    int number;
    std::cout << "Enter an integer: "
    std::cin >> number;

    if (number > 0) {
        std::cout << number << " is a positive number." << std::endl;
    } else if (number < 0) {
        std::cout << number << " is a negative number." << std::endl;
    } else {
        std::cout << "The number is zero." << std::endl;
    }

    return 0;
}