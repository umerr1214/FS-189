#include <iostream>

void swapValues(int& a int& b) { // Syntax Error: Missing comma between parameters
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1, num2;
    std::cout << "Enter first integer: ";
    std::cin >> num1;
    std::cout << "Enter second integer: ";
    std::cin >> num2;

    std::cout << "Before swapping: num1 = " << num1 << ", num2 = " << num2 << std::endl;
    swapValues(num1, num2);
    std::cout << "After swapping: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    return 0;
}