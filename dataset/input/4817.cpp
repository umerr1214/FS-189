#include <iostream>

// Function to swap two integer references (Logical Error: incorrect swap logic)
void swapValues(int& a, int& b)
{
    // Incorrect logic: Both a and b will end up with the original value of b
    a = b;
    b = a; // At this point, 'a' already holds the original value of 'b'. So 'b' is assigned 'b's original value.
}

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