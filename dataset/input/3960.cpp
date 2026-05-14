#include <iostream>

void swapValues(int a, int b) { // Semantic Error: Parameters taken by value, not by reference
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
    swapValues(num1, num2); // Calls swapValues, but on copies
    std::cout << "After swapping: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    return 0;
}