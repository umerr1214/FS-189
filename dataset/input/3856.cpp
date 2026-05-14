#include <iostream>

int main() {
    long long product = 1; // Use long long to prevent overflow for general case
    int num;

    std::cout << "Enter a series of non-zero integers (enter 0 to stop):\n";

    while (true) {
        std::cout << "Enter number: ";
        std::cin >> num;

        if (num == 0) {
            break;
        }

        product *= num;
    }

    std::cout << "Product of non-zero numbers: " << product << std::endl // MISSING SEMICOLON HERE

    return 0;
}