#include <iostream>

int main() {
    long long product = 0; // Logical error: Should be initialized to 1 for product calculation
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

    std::cout << "Product of non-zero numbers: " << product << std::endl;

    return 0;
}