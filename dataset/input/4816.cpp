#include <iostream>

// Function to swap two integer references
void swapValues(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp
} // Missing semicolon here

int main() {
    int num1, num2;

    std::cout << "Enter first integer: ";
    std::cin >> num1;

    std::cout << "Enter second integer: ";
    std::cin >> num2;

    std::cout << "Before swap: a = " << num1 << ", b = " << num2 << std::endl;

    swapValues(num1, num2);

    std::cout << "After swap: a = " << num1 << ", b = " << num2 << std::endl;

    return 0;
}