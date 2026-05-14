#include <iostream>

// Function to check if a number is even
bool isEven(int num) {
    // Logical Error: This condition checks if the number is ODD, not EVEN.
    return num % 2 != 0; 
}

int main() {
    std::cout << std::boolalpha; // To print true/false instead of 1/0
    std::cout << "isEven(4): " << isEven(4) << std::endl; // Expected: true, Actual: false
    std::cout << "isEven(7): " << isEven(7) << std::endl; // Expected: false, Actual: true
    std::cout << "isEven(0): " << isEven(0) << std::endl; // Expected: true, Actual: false
    std::cout << "isEven(-2): " << isEven(-2) << std::endl; // Expected: true, Actual: false
    std::cout << "isEven(-3): " << isEven(-3) << std::endl; // Expected: false, Actual: true
    return 0;
}