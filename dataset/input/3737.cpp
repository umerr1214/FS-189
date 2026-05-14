#include <iostream>

int main() {
    int num1, num2, num3;
    std::cout << "Enter three distinct integers: ";
    std::cin >> num1 >> num2 >> num3;

    if (num1 > num2 && num1 > num3) {
        std::cout << "The largest number is: " << num1 << std::endl;
    } else if (num2 > num1) { // Logical Error: This only checks if num2 is greater than num1,
                              // but it doesn't ensure num2 is also greater than num3.
                              // If num3 is largest and num2 > num1, this branch will incorrectly execute.
        std::cout << "The largest number is: " << num2 << std::endl;
    } else { // This implicitly assumes num3 is the largest if num1 wasn't and num2 wasn't greater than num1.
             // This is correct if num3 is truly the largest in the remaining cases, but the 'else if' above is flawed.
        std::cout << "The largest number is: " << num3 << std::endl;
    }

    return 0;
}