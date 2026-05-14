#include <iostream>

// Function to swap two integers by reference
void swapNumbers(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a, b;

    std::cout << "Enter two integers: ";
    // Robustness Issue: No input validation. If non-integer input is provided,
    // cin will enter a fail state, and subsequent operations might use
    // uninitialized values or behave unexpectedly without recovery.
    std::cin >> a >> b;

    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;

    swapNumbers(a, b);

    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    return 0;
}