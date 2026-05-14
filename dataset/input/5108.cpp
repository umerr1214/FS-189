#include <iostream>

int main() {
 double a = 0.0;
  double b = 0.0;
 char o;
  double r = 0.0;

    std::cout << "Welcome to the Simple Calculator!" << std::endl;
   std::cout << "Please enter the first number: ";
    std::cin >> a;
    if (std::cin.fail()) { std::cout << "Invalid input.\n"; return 1; }
   std::cout << "Please enter an operator (+, -, *, /): ";
    std::cin >> o;
   std::cout << "Please enter the second number: ";
    std::cin >> b;
    if (std::cin.fail()) { std::cout << "Invalid input.\n"; return 1; }

 switch (o) {
        case '+': r = a + b;
            std::cout << "Result: " << r << std::endl; break;
        case '-': r = a - b;
            std::cout << "Result: " << r << std::endl; break;
        case '*': r = a * b;
            std::cout << "Result: " << r << std::endl; break;
        case '/':
            if (b == 0) {
                std::cout << "Error: Division by zero is not allowed.\n";
                return 1;
            }
            r = a / b;
            std::cout << "Result: " << r << std::endl; break;
        default:
            std::cout << "Error: Invalid operator.\n";
            return 1;
    }

 return 0;
}