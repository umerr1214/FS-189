#include <iostream>

int main() {
    int num;
    do {
        std::cout << "Enter a positive integer: ";
        std::cin >> num;
    } while (num != 0); // Logical Error: Loop continues as long as num is not zero,
                        // meaning it accepts negative numbers and 0 as valid input.
                        // It should be 'while (num <= 0)' to ensure only positive integers are accepted.
    std::cout << "You entered: " << num << std::endl;
    return 0;
}