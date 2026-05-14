#include <iostream>
#include <string>

int main() {
    int num1, num2;

    std::cout << "Enter the first integer: ";
    std::cin >> num1;

    std::cout << "Enter the second integer: ";
    std::cin >> num2;

    int larger_val;
    std::string message;

    // Semantic Error: Uses if-else statement instead of the required ternary operator
    if (num1 > num2) {
        larger_val = num1;
        message = "The larger integer is: ";
    } else if (num2 > num1) {
        larger_val = num2;
        message = "The larger integer is: ";
    } else { // num1 == num2
        larger_val = num1; // If equal, either can be considered 'larger' in context
        message = "Both integers are equal: ";
    }

    std::cout << message << larger_val << std::endl;

    return 0;
}