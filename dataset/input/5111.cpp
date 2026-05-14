#include <iostream>

int main() {
    int num;
    do {
        std::cout << "Enter a positive integer: ";
        std::cin >> num;
    } while (num < 0); // Logical error: Should be num <= 0 to reject zero as well

    std::cout << "You entered: " << num << std::endl;

    return 0;
}