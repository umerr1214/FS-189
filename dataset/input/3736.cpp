#include <iostream>

int main() {
    int num1, num2, num3 // Syntax Error: Missing semicolon here
    std::cout << "Enter three distinct integers: ";
    std::cin >> num1 >> num2 >> num3;

    if (num1 > num2 && num1 > num3) {
        std::cout << "The largest number is: " << num1 << std::endl;
    } else if (num2 > num1 && num2 > num3) {
        std::cout << "The largest number is: " << num2 << std::endl;
    } else { // Assuming num3 is largest if previous conditions are false
        std::cout << "The largest number is: " << num3 << std::endl;
    }

    return 0;
}