#include <iostream>

int main() {
    int i; // Represents the input number
    std::cout << "Enter a positive integer: ";
    std::cin >> i;

    int s = 0; // Represents the sum of digits
    // Readability Issue:
    // Variable names 'i', 's', and 'd' are not descriptive.
    // This makes the code harder to understand at a glance,
    // especially for someone unfamiliar with the context.
    while (i > 0) {
        int d = i % 10; // Represents a single digit
        s += d;
        i /= 10;
    }

    std::cout << "The sum of the digits is: " << s << std::endl;

    return 0;
}