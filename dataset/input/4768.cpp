#include <iostream>

int main() {
    int num1, num2, num3;

    std::cout << "Enter three integers: ";
    std::cin >> num1 >> num2 >> num3;

    int largest;

    if (num1 >= num2 && num1 >= num3) {
        largest = num1;
    } else if (num2 >= num1 && num2 >= num3) {
        largest = num2;
    } else {
        largest = num3;
    }

    std::cout << "The largest number is: " << largest // Syntax error: Missing semicolon here
    return 0;
}