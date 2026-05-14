#include <iostream>

// Function to swap two integers by reference
void swapNumbers(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1, num2;

    std::cout << "Enter first number: ";
    std::cin >> num1; // Missing semicolon here, causing a syntax error
    std::cout << "Enter second number: ";
    std::cin >> num2;

    std::cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    swapNumbers(num1, num2);

    std::cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    return 0;
}