#include <iostream>

int main() {
    int number;
    int sum = 0;

    std::cout << "Enter positive integers (0 to stop):" << std::endl;

    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> number;

        if (number == 0) {
            break; // Terminate if 0 is entered, without adding it
        }
        // Logical error: The problem asks for the sum of *positive* integers.
        // This code adds ALL non-zero integers, including negative ones.
        sum += number;
    }

    std::cout << "Sum of positive integers (incorrectly calculated): " << sum << std::endl;

    return 0;
}