#include <iostream>
#include <limits> // Included for demonstrating limits, though not directly used in the logic

int main() {
    // Semantic Error: Using 'short' for integer input.
    // While syntactically correct, 'short' typically has a smaller range (e.g., -32768 to 32767)
    // than 'int'. If the user enters integers outside this range (e.g., 40000),
    // it will cause integer overflow, leading to incorrect values being stored
    // and thus incorrect comparison results, violating the intent of finding the largest
    // among arbitrary "distinct integers".
    short num1, num2, num3; 

    std::cout << "Enter three distinct integers: ";
    std::cin >> num1 >> num2 >> num3;

    if (num1 > num2 && num1 > num3) {
        std::cout << "The largest number is: " << num1 << std::endl;
    } else if (num2 > num1 && num2 > num3) {
        std::cout << "The largest number is: " << num2 << std::endl;
    } else {
        std::cout << "The largest number is: " << num3 << std::endl;
    }

    return 0;
}