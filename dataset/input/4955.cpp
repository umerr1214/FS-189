#include <iostream>

int main() {
    int sum = 0;
    int num;

    do {
        std::cout << "Enter an integer: ";
        std::cin >> num;
        // Logical Error: All numbers (positive, zero, and the final negative sentinel)
        // are added to the sum. The problem asks for the sum of *positive* numbers only.
        sum += num; 
    } while (num >= 0);

    // The sum now includes the negative number that terminated the loop,
    // and any zeros entered, which are not strictly positive.

    std::cout << "Sum of positive numbers: " << sum << std::endl;

    return 0;
}