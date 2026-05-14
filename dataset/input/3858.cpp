#include <iostream>

int main() {
    int product = 1; // Semantic error: Using 'int' for product, which can overflow for large inputs.
                     // Should use 'long long' for a larger range.
    int num;

    std::cout << "Enter a series of non-zero integers (enter 0 to stop):\n";

    while (true) {
        std::cout << "Enter number: ";
        std::cin >> num;

        if (num == 0) {
            break;
        }

        product *= num; // Potential for signed integer overflow (undefined behavior)
    }

    std::cout << "Product of non-zero numbers: " << product << std::endl;

    return 0;
}