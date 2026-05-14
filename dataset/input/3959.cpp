#include <iostream>

void swapValues(int& a, int& b) {
    a = b; // Logical Error: 'a' now holds original 'b'
    b = a; // 'b' now holds the *new* value of 'a' (which is original 'b'), so 'b' doesn't change from original
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