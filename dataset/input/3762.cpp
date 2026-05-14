#include <iostream>

// Function to swap two integers - semantic error: arguments passed by value instead of reference
void swapNumbers(int a, int b) { // Should be (int& a, int& b)
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1, num2;

    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    std::cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    swapNumbers(num1, num2); // Calls swapNumbers, but it operates on copies

    std::cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    return 0;
}