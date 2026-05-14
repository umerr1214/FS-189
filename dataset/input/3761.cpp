#include <iostream>

// Function to swap two integers by reference - contains a logical error
void swapNumbers(int& a, int& b) {
    a = b; // Assigns value of b to a
    b = a; // Assigns new value of a (which is b's original value) to b. Original value of a is lost.
}

int main() {
    int num1, num2;

    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    std::cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    swapNumbers(num1, num2);

    std::cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    return 0;
}