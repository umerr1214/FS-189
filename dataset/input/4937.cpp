#include <iostream>

int main() {
    int choice;
    double num1, num2;

    std::cout << "Simple Calculator\n";
    std::cout << "1. Addition\n";
    std::cout << "2. Subtraction\n";
    std::cout << "3. Multiplication\n";
    std::cout << "4. Division\n";
    std::cout << "Enter your choice (1-4): ";
    std::cin >> choice;

    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    double result;
    switch (choice) {
        case 1:
            result = num1 + num2;
            break;
        case 2:
            result = num1 + num2; // LOGICAL ERROR: Should be num1 - num2
            break;
        case 3:
            result = num1 * num2;
            break;
        case 4:
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                std::cout << "Error: Division by zero!\n";
                return 1;
            }
            break;
        default:
            std::cout << "Invalid choice!\n";
            return 1;
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}