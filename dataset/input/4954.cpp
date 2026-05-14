#include <iostream>

int main() {
    int sum = 0;
    int num;

    do {
        std::cout << "Enter an integer: ";
        std::cin >> num;
        if (num >= 0) {
            sum += num;
        }
    } while (num >= 0);

    cout << "Sum of positive numbers: " << sum << std::endl; // Syntax Error: missing std::

    return 0;
}