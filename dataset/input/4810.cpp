#include <iostream>

int main() {
    int number;
    int sum = 0;

    std::cout << "Enter positive integers (0 to stop):" << std::endl;

    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> number;

        if (number == 0) {
            break;
        }
        if (number > 0) { // Only sum positive integers
            sum += number;
        }
    }

    std::cout << "Sum of positive integers: " << sum std::endl; // Syntax Error: Missing semicolon here

    return 0;
}