#include <iostream>
#include <string> // For std::to_string

int main() {
    int num1, num2;

    std::cout << "Enter the first integer: ";
    std::cin >> num1;

    std::cout << "Enter the second integer: ";
    std::cin >> num2;

    std::string result_message;

    // Using the ternary operator to concisely determine the larger integer
    // and construct an appropriate message, including handling equality.
    result_message = (num1 > num2) ? "The first integer (" + std::to_string(num1) + ") is larger." :
                     (num2 > num1) ? "The second integer (" + std::to_string(num2) + ") is larger." :
                     "The two integers are equal.";

    std::cout << result_message << std::endl;

    return 0;
}