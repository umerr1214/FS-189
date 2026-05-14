#include <iostream>

// Function to swap two integer values (Semantic Error: takes by value, not reference as required)
void swapValues(int a, int b) // Semantic error: parameters are passed by value, not by reference
{
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

    std::cout << "Before swap: a = " << num1 << ", b = " << num2 << std::endl;

    swapValues(num1, num2); // This call passes copies of num1 and num2

    std::cout << "After swap: a = " << num1 << ", b = " << num2 << std::endl; // num1 and num2 remain unchanged

    return 0;
}