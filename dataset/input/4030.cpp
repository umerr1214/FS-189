#include <iostream>

int main() {
    int num1, num2, num3;
    int temp;

    std::cout << "Enter three distinct integer numbers: ";
    std::cin >> num1 >> num2 >> num3;

    // A deliberate syntax error: missing semicolon after std::endl
    std::cout << "You entered: " << num1 << " " << num2 << " " << num3 << std::endl

    // Correct sorting logic (if it compiled)
    if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    if (num1 > num3) {
        temp = num1;
        num1 = num3;
        num3 = temp;
    }
    if (num2 > num3) {
        temp = num2;
        num2 = num3;
        num3 = temp;
    }

    std::cout << "Sorted numbers: " << num1 << " " << num2 << " " << num3 << std::endl;

    return 0;
}